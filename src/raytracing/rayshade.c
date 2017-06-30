/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 15:50:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"
#include "rt_tools.h"

t_rtrd		raysky(t_rtrd rdata, t_rayd *rayd)
{
	rdata.geo.flags = 0;
	rdata.lgeo.flags = 0;
	rdata.frag = shade_sky(&rdata, rayd->tree);
	return (rdata);
}

t_rtrd		shadowshade(t_rtrd rdata, t_rtrgd gd, t_rayd *rayd, t_ui num)
{
	t_rtmat	*mat;

	if (!(gd.flags & RAY_GVALID))
		return (raysky(rdata, rayd));
	rdata.lgeo = gd;
	rdata.lray = gd.ray;
	geo_gnor(&rdata);
	geo_tan(&rdata);
	rdata.geo = geo_getglobal(rdata.lgeo, rayd->ray);
	mat = ((t_rtobd *)(rdata.lgeo.inst->obj))->plan.material;
	rdata.frag = shade_diffuse(&rdata, mat);
	return (shadow_transmit(rdata, rayd, num));
}

t_rtrd		rayshade(t_rtrd rdata, t_rtrgd gd, t_rayd *rayd, t_ui num)
{
	if (!(gd.flags & RAY_GVALID))
		return (raysky(rdata, rayd));
	rdata.lgeo = gd;
	rdata.lray = gd.ray;
	geo_gnor(&rdata);
	geo_tan(&rdata);
	rdata.geo = geo_getglobal(rdata.lgeo, rayd->ray);
	rdata.frag = rdr_shade(rdata, rayd->tree);
	return (rdr_transmit(rdata, rayd, num));
}

t_rtrfd		rdr_shade(t_rtrd rdata, t_rdrtree *tree)
{
	t_rtmat	*mat;
	t_rtrfd	frag;

	mat = ((t_rtobd *)(rdata.lgeo.inst->obj))->plan.material;
	frag = shade_diffuse(&rdata, mat);
	frag.hit_nor = shade_normale(&rdata, mat);
	rdata.geo.hit_nor = frag.hit_nor;
	pv3fmulv3f((t_v3f *)&frag.color, shade_lightsloop(rdata.geo, tree));
	return (frag);
}
