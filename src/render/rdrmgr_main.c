/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/04 12:41:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));

	rt_state(rt, RTS_RENDER, RT_UNSET);
	pthread_mutex_unlock(&(rt->render.refresh_lock));
}

int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));
	if (!(rt->render.flags & RTRMGR_REFRESH))
		pthread_cond_wait(&(rt->render.refresh_cond),
			&(rt->render.refresh_lock));
	if (*((t_ul *)&(rmgr->rsize)) != *((t_ul *)&(rt->render.render_size)))
	{
		rmgr->rsize = rt->render.render_size;
		ft_memdel(&(rmgr->rpx));
	}
	if (!rmgr->rpx)
		rmgr->rpx = malloc(rmgr->rsize.x * rmgr->rsize.y * sizeof(t_rgba));
	// Make render tree
	rt_state(rt, RTS_RENDER, RT_SET);
	pthread_mutex_unlock(&(rt->render.refresh_lock));
}

int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr)
{
	if (!rt_isrunning(rt) || (rt->render.flags & RTRMK_STOP))
		return (0);
	if (rt->render.flags & RTRMK_CANCEL)
		return (RTRMK_CANCEL);
	return (RTRMGR_STARTRENDER);
}

void		*rdrmgr_exit(t_rt *rt, int code)
{
	return (NULL);
}

void		*rt_rdrmgr_main(void *arg)
{
	t_rt		*rt;
	t_rtrmgr	rmgr;

	rmgr.rpx = NULL;
	rt = (t_rt *)arg;
	while (rdrmgr_isrendering(rt, &rmgr))
	{
		rdrmgr_sync(rt, &rmgr);
		// Le rendu commence ici

	}
	pthread_exit(rdrmgr_exit(rt, 0));
}
