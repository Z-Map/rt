/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:51:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 18:29:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_viewer.h"

int				rt_init_window(t_rt *rt)
{
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	pthread_mutex_lock(&(rt->viewer.refresh_lock));
	rt_state(rt, RTS_VPREV, RT_SET);
	mglw_setGLContext(rt->viewer.win);
	viewer_clearlayer(rt);
	if (!(rt->viewer.font = mgl_ttf_to_charatlas("font.ttf", NULL, 0)))
		return (rt_error(240, "Font loading failed."));
	rt->viewer.ui =
		init_ui(rt, (t_v2i){RT_DEFAULT_RSIZE_X, RT_DEFAULT_RSIZE_Y});
	update_ui(rt->viewer.ui);
	pthread_mutex_unlock(&(rt->viewer.refresh_lock));
	RT_DBGM("Viewer window started.");
	return (0);
}

int				viewer_run(t_rt *rt, t_rtview *v)
{
	pthread_mutex_lock(&(v->refresh_lock));
	mglwin_draw(v->win);
	mglw_setGLContext(NULL);
	if (!(v->keys & RTWK_REFRESH))
		pthread_cond_wait(&(v->refresh_cond), &(v->refresh_lock));
	if (rt->flags & RTF_CLEARLAYER)
		viewer_clearlayer(rt);
	v->keys &= ~RTWK_REFRESH;
	if ((v->keys & RTWK_STOP) || !rt_isrunning(rt))
	{
		mglw_setGLContext(NULL);
		pthread_mutex_unlock(&(v->refresh_lock));
		return (0);
	}
	mglw_setGLContext(v->win);
	mglwin_clear(v->win);
	if (rt->flags & RTF_RDRDISP)
		mglw_draw_itow(v->win, v->rdrtarget, 0, 0);
	pthread_mutex_unlock(&(v->refresh_lock));
	return (1);
}

void			*viewer_exit(t_rt *rt, int code)
{
	rt->error = code;
	pthread_mutex_lock(&(rt->viewer.refresh_lock));
	rt->viewer.keys |= RTWK_STOP | RTWK_REFRESH;
	if (rt->viewer.font)
		mgl_delcharatlas(&(rt->viewer.font));
	delui(rt->viewer.ui);
	rt_state(rt, RTS_VPREV, RT_UNSET);
	pthread_mutex_unlock(&(rt->viewer.refresh_lock));
	viewer_run(rt, &(rt->viewer));
	RT_DBGM("Viewer window stoped.");
	return (NULL);
}

void			*rt_viewer_main(void *arg)
{
	t_rt		*rt;

	rt = (t_rt *)arg;
	if (rt_init_window(rt))
		pthread_exit(viewer_exit(rt,
			rt_error(-124, "error on viewer init")));
	while (viewer_run(rt, &(rt->viewer)))
	{
		viewer_loop(rt);
	}
	pthread_exit(viewer_exit(rt, 0));
}
