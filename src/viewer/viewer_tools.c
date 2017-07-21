/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:21:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:39:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"

void			viewer_clearlayer(t_rt *rt)
{
	rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	if (rt->viewer.layer)
		ft_bzero(rt->viewer.layer->pixels, rt->viewer.layer->memlen);
	rt->flags &= ~RTF_CLEARLAYER;
}
