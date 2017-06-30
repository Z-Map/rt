/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 10:36:08 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

// t_rtrd		shadowtrace(t_rtray ray, t_rtrld l, t_rdrtree *tree, t_ui raycount)
// {
// 	t_rtmat	*mat;
// 	t_rtrd	rdata;
// 	t_v4f	a;
//
// 	rdata.frag.color = (t_v4f){l.color.x, l.color.y, l.color.z, 1.0f};
// 	rdata.lgeo = rdr_raycast(ray, tree, l.depth);
// 	rdata.frag.color.w = (rdata.lgeo.flags & RAY_GVALID) ? 0.0f : 1.0f;
// 	geo_gnor(&rdata);
// 	rdata.geo = geo_getglobal(rdata.lgeo, ray);
// 	if (!raycount || !(rdata.lgeo.flags & RAY_GVALID)
// 		|| (rdata.geo.hit_point.w > l.depth))
// 		return (rdata);
// 	mat = ((t_rtobd *)(rdata.geo.inst->obj))->plan.material;
// 	rdata.frag = shade_diffuse(rdata, mat, tree);
// 	rdata.frag.color.w = 1.0f - rdata.frag.color.w;
// 	a.x = mxmaxf(rdata.frag.color.z,
// 		mxmaxf(rdata.frag.color.x, rdata.frag.color.y));
// 	if (rdata.frag.color.w <= 0.0f)
// 		return (rdata);
// 	pv4faddv4f(&rdata.frag.color, nv4f((1.0 - a.x) * 0.3));
// 	a = rdata.frag.color;
// 	l.color = v4to3f(rdata.frag.color);
// 	l.depth -= rdata.geo.hit_point.w;
// 	rdata = shadowtrace(ray_transmit(rdata.geo, l.v), l, tree, raycount - 1);
// 	if (rdata.geo.hit_point.w < l.depth)
// 	{
// 		rdata.frag.color.x = mxminf(rdata.frag.color.x, a.x);
// 		rdata.frag.color.y = mxminf(rdata.frag.color.y, a.y);
// 		rdata.frag.color.z = mxminf(rdata.frag.color.z, a.z);
// 		rdata.frag.color.w *= a.w;
// 	}
// 	else
// 		rdata.frag.color.w = a.w;
// 	return (rdata);
// }

t_rtrd		raytrace(t_rayd *rayd)
{
	t_rtrd	rdata;
	int		i;

	rdata.tree = rayd->tree;
	rdata.ray = rayd->ray;
	i = RDR_GEOSTACK;
	while (i--)
		rayd->geostack[i].flags = 0;
	if (!rdr_raycast(rayd, rayd->tree))
		return (rdata);
	rayshade(rdata, rayd->geostack[0], rayd);
	return (rdata);
}
