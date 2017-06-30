/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:21:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 14:48:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"

void			viewer_clearlayer(t_rt *rt)
{
	rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	ft_bzero(rt->viewer.layer->pixels, rt->viewer.layer->memlen);
	rt->flags &= ~RTF_CLEARLAYER;
}
