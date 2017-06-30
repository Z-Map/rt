/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/29 21:07:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

int			intersect_depth(t_rtrgd *gd, t_rtray r, t_v2f d)
{
	int			ret;

	ret = 0;
	if ((d.x > gd[0].depth) && (d.x < gd[1].depth))
		ret |= geo_setdepth(gd, 1, d.x);
	if ((d.y < gd[1].depth) && (d.y > gd[0].depth))
		ret |= geo_setdepth(gd + 1, 2, d.y);
	gd[0].hit_point = ray_hitpoint(r, gd[0].depth);
	gd[1].hit_point = ray_hitpoint(r, gd[1].depth);
	return (ret);
}

int			geo_setdepth(t_rtrgd *gd, int dim, float depth)
{
	gd->depth = depth;
	gd->flags &= ~RAY_GINFO;
	gd->flags |= RAY_GDEPTH | RAY_GINTER | RAY_GLOCAL;
	return (dim);
}

t_rtrgd		geo_getglobal(t_rtrgd gd, t_rtray r)
{
	t_mattf	m;

	if (!(gd.flags & RAY_GVALID))
		return (gd);
	if (gd.flags & RAY_GLOCAL)
	{
		m = gd.node->transform;
		m.offset = nv3f(0.0f);
		if (gd.flags & RAY_GHTANG)
		{
			pmattf_apply(&(gd.hit_tangent.x), &m);
			pmattf_apply(&(gd.hit_tangent.y), &m);
		}
		if (gd.flags & RAY_GHNOR)
			pmattf_apply(&(gd.hit_nor), &m);
	}
	gd.hit_point = ray_hitpoint(r, gd.depth);
	return (gd);
}
