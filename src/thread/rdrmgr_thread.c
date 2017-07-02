/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:56:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mglw/mglw.h"
#include "mathex/utils.h"
#include "rt_render.h"

/*
** rt_sync_rdrmgrthread(rt);
*/

int			rdrmgr_render_request(t_rt *rt, t_rtree *tree)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));
	rt->render.flags |= RTRMK_CANCEL | RTRMK_REFRESH;
	rt->render.target = tree;
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	return (1);
}

static void	rt_sync_rdrdone(t_rt *rt)
{
	mglimg	*img;

	if (rt_state(rt, RTS_MGLW_INIT, RT_GET))
	{
		pthread_mutex_lock(&(rt->viewer.refresh_lock));
		img = rt->viewer.rdrtarget;
		if (img->pixels)
			free(img->pixels);
		img->x = rt->render.render_size.x;
		img->y = rt->render.render_size.y;
		img->bpp = sizeof(t_v4f);
		img->format = MGLW_RGBA;
		img->type = MGLW_FLOAT;
		img->memlen = img->x * img->y * sizeof(t_v4f);
		img->pixels = (t_uc *)(rt->render.render_px);
		rt->render.render_px = NULL;
		rt->flags |= RTF_RDRDISP;
		rt->viewer.keys |= RTWK_REFRESH;
		pthread_mutex_unlock(&(rt->viewer.refresh_lock));
	}
	rt->render.flags &= ~RTRMK_DONE;
	if (rt->flags & RTF_RDRAUTO)
		rt->flags |= RTF_RDRREFRESH;
}

int			rt_sync_rdrmgrthread(t_rt *rt)
{
	if (!rt_state(rt, RTS_RDRMGR_INIT, RT_GET))
		return (0);
	pthread_mutex_lock(&(rt->render.refresh_lock));
	if (rt->render.flags & RTRMK_DONE)
		rt_sync_rdrdone(rt);
	if (!rt_state(rt, RTS_RENDER, RT_GET) && (rt->flags & RTF_RDRREFRESH))
	{
		if (!(rt->render.target))
			rt->render.target = rt->tree;
		rt->render.flags |= RTRMK_REFRESH;
		rt->flags &= ~RTF_RDRREFRESH;
	}
	if (!rt_isrunning(rt))
		rt->render.flags |= RTRMK_STOP | RTRMK_REFRESH;
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	if (rt->render.flags & RTRMK_REFRESH)
		pthread_cond_broadcast(&(rt->render.refresh_cond));
	if (!rt_isrunning(rt))
		pthread_join(rt->render.mgrthread, NULL);
	return (1);
}

int			rt_init_rdrmgrthread(t_rt *rt)
{
	rt->render.flags = 0;
	rt->render.refresh_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	rt->render.refresh_cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	if (pthread_create(&(rt->render.mgrthread), NULL, &rt_rdrmgr_main, rt))
		return (rt_error(-122, "Unable to start render thread."));
	return (1);
}
