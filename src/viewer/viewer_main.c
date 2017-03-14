/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:51:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 19:52:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_viewer.h"

int				viewer_run(t_rt *rt, t_rtview *v)
{
	mglwin_draw(v->win);
	mglw_setGLContext(NULL);
	if (!(v->keys & RTWK_REFRESH))
		pthread_cond_wait(&(v->refresh_cond), &(v->refresh_lock));
	if (v->keys & RTWK_STOP)
	{
		mglw_setGLContext(NULL);
		return (0);
	}
	mglwin_clear(v->win);
	mglw_setGLContext(v->wins);
	return (1);
}

int				rt_init_window(t_rt *rt)
{
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	ft_bzero(rt->viewer.layer->pixels, rt->viewer.layer->memlen);
	return (0);
}

void			*rt_viewer_main(void *arg)
{
	t_rt		*rt;

	rt = (t_rt *)arg;
	if (rt_init_window(rt))
		pthread_exit(NULL);
	while (viewer_run(rt, &(rt->viewer)))
	{
		viewer_loop(rt);
	}
	pthread_exit(NULL);
}
