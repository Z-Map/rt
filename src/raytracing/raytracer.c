/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 18:47:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		shadowtrace(t_rtray ray, t_rtrld l, t_rdrtree *tree, t_ui raycount)
{
	t_rtmat	*mat;
	t_rtrd	rdata;
	t_v4f	a;

	rdata.lgeo = rdr_raycast(ray, tree, l.depth);
	rdata.frag.color.w = (rdata.lgeo.flags & RAY_GVALID) ? 0.0f : 1.0f;
	rdata.lgeo.flags &= ~RAY_GLOCAL;
	rdata.geo = geo_getglobal(rdata.lgeo, ray);
	if (!raycount || !(rdata.lgeo.flags & RAY_GVALID)
		|| (rdata.geo.hit_point.w > l.depth))
		return (rdata);
	mat = ((t_rtobd *)(rdata.geo.inst->obj))->plan.material;
	rdata.frag = shade_diffuse(rdata, mat, tree);
	rdata.frag.color.w = 1.0f - rdata.frag.color.w;
	if (rdata.frag.color.w <= 0.0f)
		return (rdata);
	a = rdata.frag.color;
	l.depth -= rdata.geo.hit_point.w;
	rdata = shadowtrace(ray_transmit(rdata.geo, l.v), l, tree, raycount - 1);
	if (rdata.geo.hit_point.w < l.depth)
	{
		rdata.frag.color.x = mxminf(rdata.frag.color.x, a.x);
		rdata.frag.color.y = mxminf(rdata.frag.color.y, a.y);
		rdata.frag.color.z = mxminf(rdata.frag.color.z, a.z);
		rdata.frag.color.w *= a.w;
	}
	else
		rdata.frag.color.w = a.w;
	return (rdata);
}

t_rtrd		raytrace(t_rtray ray, t_rdrtree *tree, t_ui raycount)
{
	t_rtrd	rdata;

	(void)raycount;
	rdata.tree = tree;
	rdata.ray = ray;
	rdata.lgeo = rdr_raycast(ray, tree, INFINITY);
	rdata.lray = rdata.lgeo.ray;
	geo_gnor(&rdata);
	geo_tan(&rdata);
	rdata.geo = geo_getglobal(rdata.lgeo, ray);
	rdata.frag = rdr_shade(rdata, tree);
	return (rdr_transmit(rdata, tree, raycount));
	// return (rdata);
}
