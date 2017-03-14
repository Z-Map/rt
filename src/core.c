/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:06:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 16:21:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			rt_init_scenerdr(t_rt *rt)
{
	rt->state = RTS_INIT;
	return (1);
}

int			rt_init_mglw(t_rt *rt)
{
	if (!mglw_init())
		return (rt_error(rt, 121, "Unable to init mglw."));
	rt->state |= RTS_MGLW_INIT;
	// if ((!(rt->viewer.win = mglw_openwin(
	// 		mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
	// 		1400, 900, "-=[ |RT| ]=-"))))
	// 	return (-120);
	// mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	// rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	// ft_bzero(rt->viewer.layer->pixels, rt->viewer.layer->memlen);
	rt_init_viewerthread(rt);
	return (1);
}

int			rt_run(t_rt *rt)
{
	if ((rt->state & RTS_VPREV) && !mglwin_run(rt->viewer.win))
		rt->state &= ~RTS_VPREV;
	else if (rt->state & RTS_VPREV)
		viewer_loop(rt);
	if ((rt->flags & RT_VISUALPREV) && !(rt->state & RTS_VPREV))
		rt->state |= RTS_QUIT;
	return (0);
}

int			rt_isrunning(t_rt *rt)
{
	if (!(rt->state & RTS_INIT) ||
		(rt->state & RTS_QUIT))
		return (0);
	return (1);
}

int			rt_main(t_rt *rt)
{
	int		ret;

	ret = rt_init_scenerdr(rt);
	if ((rt->flags & RT_VISUALPREV) ||
		!(rt->flags & (RT_FILEOUT|RT_COMMANDMODE)))
		ret = rt_init_mglw(rt);
	if (ret <= 0)
		return (ret);
	while (rt_isrunning(rt))
		ret = rt_run(rt);
	return (ret);
}
