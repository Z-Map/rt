/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 07:11:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

int			rdrmgr_render_request(t_rt *rt, t_rtree *tree)
{
	pthread_mutex_lock(&(rt->render.refresh_lock));
	rt->render.flags |= RTRMK_CANCEL|RTRMK_REFRESH;
	rt->render.target = tree;
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	rt_sync_rdrmgrthread(rt);
	return (1);
}

int			rt_sync_rdrmgrthread(t_rt *rt)
{
	if (!rt_state(rt, RTS_RDRMGR_INIT, RT_GET))
		return (0);
	pthread_mutex_lock(&(rt->render.refresh_lock));
	if (!rt_isrunning(rt))
		rt->render.flags |= RTRMK_STOP|RTRMK_REFRESH;
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
		return (rt_error(rt, 122, "Unable to start render thread."));
	return (1);
}
