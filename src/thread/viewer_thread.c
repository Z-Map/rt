/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:57:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 19:56:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_core.h"
#include "rt_viewer.h"

int			rt_sync_viewerthread(t_rt *rt)
{
	int			ret;
	t_rtview	*v;

	if (!(rt->state & RTS_VPREV))
		return (0);
	v = &(rt->viewer);
	pthread_mutex_lock(&(v->refresh_lock));
	if (!(ret = mglwin_process_event(v->win)))
		v->keys |= RTWK_STOP;
	pthread_mutex_unlock(&(v->refresh_lock));
	pthread_cond_broadcast(&(v->refresh_cond));
	if (!ret)
	{
		pthread_join(&(v->mainthread), NULL);
		mglw_closewin(v->win);
		rt->state &= ~RTS_VPREV;
		if (rt->flags & RT_VISUALPREV)
			rt->flags &= ~RT_VISUALPREV;
	}
	return (0);
}

int			rt_init_viewerthread(t_rt *rt)
{
	if (!(rt->state & RTS_MGLW_INIT) && (rt_init_mglw(rt) <= 0))
		return (rt->error);
	if (!(rt->viewer.win = mglw_openwin(
		mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER), 1400, 900, "-=[ |RT| ]=-")))
		return (rt_error(rt, 120, "Unable to open main window."));
	mglw_setGLContext(NULL);
	rt->viewer.keys = RTWK_REFRESH;
	rt->viewer.refresh_lock = PTHREAD_MUTEX_INITIALIZER;
	rt->viewer.refresh_cond = PTHREAD_COND_INITIALIZER;
	if (pthread_create(&(rt->viewer.mainthread), NULL, &rt_viewer_main, rt))
		return (rt_error(rt, 122, "Unable to start viewer thread."));
	rt->state |= RTS_VPREV;
	// rt_init_window(rt);
	return (1);
}
