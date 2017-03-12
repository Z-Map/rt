/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:57:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 16:23:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_core.h"
#include "rt_viewer.h"

int			rt_init_viewerthread(t_rt *rt)
{
	if (!(rt->state & RTS_MGLW_INIT) && (rt_init_mglw(rt) <= 0))
		return (rt->error);
	if (!(rt->viewer.win = mglw_openwin(
		mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER), 1400, 900, "-=[ |RT| ]=-")))
		return (rt_error(rt, 120, "Unable to open main window."));
	rt->state |= RTS_VPREV;
	// if (pthread_create(&(rt->viewer.mainthread), NULL, &rt_viewer_main, rt))
	// 	return (rt_error(rt, 122, "Unable to start viewer thread."));
	rt_init_window(rt);
	return (1);
}
