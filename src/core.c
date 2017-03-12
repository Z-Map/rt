/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:06:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 14:51:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			rt_init_scenerdr(t_rt *rt)
{
	(void)rt;
	return (0);
}

int			rt_init_mglw(t_rt *rt)
{
	if (!mglw_init())
		return (-121);
	rt->state |= RTS_VPREV;
	// if ((!(rt->gui.win = mglw_openwin(
	// 		mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
	// 		1400, 900, "-=[ |RT| ]=-"))))
	// 	return (-120);
	// mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	// rt->gui.layer = (mglimg *)mglw_get2dlayer(rt->gui.win);
	// ft_bzero(rt->gui.layer->pixels, rt->gui.layer->memlen);
	return (0);
}

int			rt_run(t_rt *rt)
{
	if ((rt->state & RTS_VPREV) && !mglwin_run(rt->gui.win))
		rt->state |= RTS_QUIT;
	return (0);
}

int			rt_main(t_rt *rt)
{
	int		ret;

	ret = rt_init_scenerdr(rt);
	if ((rt->flags & RT_VISUALPREV) ||
		!(rt->flags & (RT_FILEOUT|RT_COMMANDMODE)))
		ret = rt_init_mglw(rt);
	if (ret)
		return (ret);
	while (!(rt->state & RTS_QUIT))
		ret = rt_run(rt);
	return (ret);
}
