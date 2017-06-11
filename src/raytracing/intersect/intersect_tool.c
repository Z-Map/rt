/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/09 17:49:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

int			intersect_depth(t_rtrgd *gd, t_rtray r, t_v2f d, t_v3f hp[2])
{
	int			ret;

	ret = 0;
	if ((d.x > gd->depth.x) && (d.x < gd->depth.y))
		ret |= geo_setdepth(gd, 1, d.x);
	if ((d.y < gd->depth.y) && (d.y > gd->depth.x))
		ret |= geo_setdepth(gd, 2, d.y);
	hp[0] = ray_hitpoint(r, gd->depth.x);
	hp[1] = ray_hitpoint(r, gd->depth.y);
	return (ret);
}

int			geo_setdepth(t_rtrgd *gd, int dim, float depth)
{
	if (dim & 1)
	{
		gd->depth.x = depth;
		gd->flags |= RAY_GDEPTH0;
		gd->flags |= RAY_GHNOR0;
	}
	if (dim & 2)
	{
		gd->depth.y = depth;
		gd->flags |= RAY_GDEPTH1;
		gd->flags |= RAY_GHNOR1;
	}
	return (dim);
}

t_rtrgd		geo_getglobal(t_rtrgd gd, t_rtray r)
{
	t_mattf	m;

	if (!(gd.flags & RAY_GVALID))
		return (gd);
	m = gd.node->transform;
	m.offset = nv3f(0.0f);
	if (gd.flags & RAY_LOCAL0)
		pmattf_apply(gd.hit_nor, &m);
	if (gd.flags & RAY_LOCAL1)
		pmattf_apply(gd.hit_nor + 1, &m);
	if (gd.depth.x >= 0.0f)
	{
		*(t_v3f *)(&gd.hit_point) = ray_hitpoint(r, gd.depth.x);
		gd.hit_point.w = gd.depth.x;
	}
	else
	{
		*(t_v3f *)(&gd.hit_point) = ray_hitpoint(r, gd.depth.y);
		gd.hit_point.w = gd.depth.y;
	}
	return (gd);
}
