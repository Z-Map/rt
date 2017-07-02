/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 14:25:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));
	rt_state(rt, RTS_RENDER, RT_UNSET);
	rt->render.render_px = rmgr->rpx;
	rt->render.render_size = rmgr->rsize;
	rmgr->rpx = NULL;
	rmgr->rdrstate = RTRMGR_FINISHED;
	rt->render.flags |= RTRMK_DONE;
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	return (1);
}

int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));
	if (rmgr->rendertree)
		rmrtree((t_rtree **)&(rmgr->rendertree));
	if (!(rt->render.flags & RTRMGR_REFRESH))
		pthread_cond_wait(&(rt->render.refresh_cond),
			&(rt->render.refresh_lock));
	rt->render.flags &= ~(RTRMK_CANCEL | RTRMK_DONE | RTRMGR_REFRESH);
	if (!rdrmgr_isrendering(rt, rmgr))
		return (0);
	if (*((t_ul *)&(rmgr->rsize)) != *((t_ul *)&(rt->render.target_size)))
	{
		rmgr->rsize = rt->render.target_size;
		ft_memdel((void **)&(rmgr->rpx));
	}
	if ((!rmgr->rpx) &&
		!(rmgr->rpx = malloc(rmgr->rsize.x * rmgr->rsize.y * sizeof(t_v4f))))
		rt->render.flags |= RTRMK_CANCEL;
	else
	{
		rmgr->rendertree = mkrendertree(rt->render.target);
		rt->render.target = NULL;
		rt_state(rt, RTS_RENDER, RT_SET);
		rmgr->rdrstate = RTRMGR_STARTRENDER;
		pthread_mutex_unlock(&(rt->render.refresh_lock));
	}
	return (1);
}

int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr)
{
	if (!rt_isrunning(rt) || (rt->render.flags & RTRMK_STOP))
		return (0);
	if (rt->render.flags & RTRMK_CANCEL)
		return (RTRMK_CANCEL);
	return (rmgr->rdrstate);
}

void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr)
{
	RT_DBGM("Render manager stoped.");
	rt_state(rt, RTS_RDRMGR_INIT, RT_UNSET);
	if (rmgr->rpx)
		free(rmgr->rpx);
	if (rmgr->rendertree)
		rmrtree((t_rtree **)&(rmgr->rendertree));
	return (NULL);
}

void		*rt_rdrmgr_main(void *arg)
{
	t_rt		*rt;
	t_rtrmgr	rmgr;

	rmgr.filter.color.r = 0;
	rmgr.filter.color.g = 0;
	rmgr.filter.color.b = 255;
	rmgr.filter.color.a = 255;
	rt = (t_rt *)arg;
	rmgr.rpx = NULL;
	rmgr.rdrstate = RTRMGR_FINISHED;
	rmgr.rendertree = NULL;
	rt_state(rt, RTS_RDRMGR_INIT, RT_SET);
	RT_DBGM("Render manager started.");
	while (rdrmgr_isrendering(rt, &rmgr))
	{
		if (!rdrmgr_sync(rt, &rmgr))
			break ;
/* Modifications (Eddy) à vérifier */
		if (rdr_start_workers(rt, &rmgr) < RTRMGR_FINISHED)
			continue ;
		// filter_apply(&rmgr);
		rdrmgr_done(rt, &rmgr);
	}
	pthread_exit(rdrmgr_exit(rt, &rmgr));
}
