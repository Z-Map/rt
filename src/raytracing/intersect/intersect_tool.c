/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/26 20:10:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int		intersect_depth(t_rtrgd *gd, t_v2d dist, t_v3f hitp[2])
{
	int			ret;

	ret = 0;
	if ((dist.x > gd->depth.x) && (dist.x < gd->depth.y))
	{
		gd->depth.x = dist.x;
		ret = 1;
	}
	if ((dist.y < gd->depth.y) && (dist.y > gd->depth.x))
	{
		gd->depth.y = dist.y;
		ret = 2;
	}
	return (ret);
}
