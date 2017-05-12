/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 15:40:45 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr)
{
	rmgr = NULL; // A ENLEVER
	pthread_mutex_lock(&(rt->render.refresh_lock));
	rt_state(rt, RTS_RENDER, RT_UNSET);
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	return (1);
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
		ft_memdel((void **)&(rmgr->rpx));
	}
	if (!rmgr->rpx)
		rmgr->rpx = malloc(rmgr->rsize.x * rmgr->rsize.y * sizeof(t_rgba));
// Make render tree
	rt_state(rt, RTS_RENDER, RT_SET);
	pthread_mutex_unlock(&(rt->render.refresh_lock));
	return (1);
}

int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr)
{
	rmgr = NULL; // A ENLEVER
	if (!rt_isrunning(rt) || (rt->render.flags & RTRMK_STOP))
		return (0);
	if (rt->render.flags & RTRMK_CANCEL)
		return (RTRMK_CANCEL);
	return (RTRMGR_STARTRENDER);
}

void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr, int code)
{
	rt = NULL; // A ENLEVER;
	code = 0; // A ENLEVER;
	if (rmgr->rpx)
		free(rmgr->rpx);
	return (NULL);
}

void		*rt_rdrmgr_main(void *arg)
{
	t_rt		*rt;
	t_rtrmgr	rmgr;
	int			get;

	rt = (t_rt *)arg;
	rmgr.rpx = NULL;
	while (rdrmgr_isrendering(rt, &rmgr))
	{
		rdrmgr_sync(rt, &rmgr);
/* Modifications (Eddy) à vérifier */
		get = img_calc(rt, &rmgr);
		if (get < RTRMGR_STARTRENDER)
			continue ;
		rdrmgr_done(rt, &rmgr);
	}
	pthread_exit(rdrmgr_exit(rt, &rmgr, 0));
}
