/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:57:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 14:54:57 by qloubier         ###   ########.fr       */
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
	if (!(ret = mglwin_process_event(v->win)) || !rt_isrunning(rt))
		v->keys |= RTWK_STOP | RTWK_REFRESH;
	if (v->keys & RTWK_STOP)
		ret = 0;
	pthread_mutex_unlock(&(v->refresh_lock));
	if (v->keys & RTWK_REFRESH)
		pthread_cond_broadcast(&(v->refresh_cond));
	if ((!ret) || !rt_isrunning(rt))
	{
		pthread_join(v->mainthread, NULL);
		mglw_closewin(v->win);
		if (rt->flags & RT_VISUALPREV)
			rt->flags &= ~RT_VISUALPREV;
	}
	return (0);
}

/*
** rt_init_window(rt);
*/

int			rt_init_viewerthread(t_rt *rt)
{
	if (!(rt->state & RTS_MGLW_INIT) && (rt_init_mglw(rt) <= 0))
		return (rt->error);
	if (!(rt->viewer.win = mglw_openwin(
		mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER), rt->render.target_size.x,
		rt->render.target_size.y, "-=[ |RT| ]=-")))
		return (rt_error(230, "Unable to open main window."));
	mglw_setGLContext(NULL);
	mglw_setkcb(rt->viewer.win, 3, &rt_keypress, rt);
	mglw_setkcb(rt->viewer.win, 0, &rt_keyrelease, rt);
	mglw_setmcb(rt->viewer.win, 0, &rt_mousemove, rt);
	mglw_setsizecb(rt->viewer.win, &rt_resize, rt);
	rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	rt->viewer.keys = RTWK_REFRESH;
	rt->viewer.refresh_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	rt->viewer.refresh_cond = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
	if (pthread_create(&(rt->viewer.mainthread), NULL, &rt_viewer_main, rt))
		return (rt_error(122, "Unable to start viewer thread."));
	rt->flags |= RT_VISUALPREV;
	return (1);
}
