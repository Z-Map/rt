/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/09 19:14:41 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

int			rt_init_rdrmgrthread(t_rt *rt)
{
	rt->render.refresh_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	rt->render.refresh_cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	if (pthread_create(&(rt->render.mgrthread), NULL, &rt_rdrmgr_main, rt))
		return (rt_error(rt, 122, "Unable to start render thread."));
	return (1);
}

int			rt_sync_rdrmgrthread(t_rt *rt)
{
	rt = NULL; // A ENLEVER
	return (1);
}
