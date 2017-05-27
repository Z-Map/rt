/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 04:41:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

int		intersect_depth(t_rtrgd *gd, t_rtray r, t_v2d d, t_v3f hp[2])
{
	int			ret;

	ret = 0;
	if ((d.x > gd->depth.x) && (d.x < gd->depth.y))
	{
		gd->depth.x = d.x;
		ret = 1;
	}
	if ((d.y < gd->depth.y) && (d.y > gd->depth.x))
	{
		gd->depth.y = d.y;
		ret = 2;
	}
	hp[0] = ray_hitpoint(r, gd->depth.x);
	hp[1] = ray_hitpoint(r, gd->depth.y);
	return (ret);
}
