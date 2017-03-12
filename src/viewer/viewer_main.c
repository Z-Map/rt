/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:51:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 15:46:07 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"

int					rt_init_window(t_rt *rt)
{
	if ((!(rt->gui.win = mglw_openwin(
						mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
						1400, 900, "-=[ |RT| ]=-"))))
		return (-120);
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
		rt->state |= RTS_QUIT;
	
}
