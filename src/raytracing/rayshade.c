/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/20 21:11:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"

t_rtrfd		rayshade(t_rtrgd *gd, t_rayd rayd)
{
	geo_gnor(&rdata);
	geo_tan(&rdata);
	rdata.geo = geo_getglobal(rdata.lgeo, ray);
	rdata.frag = rdr_shade(rdata, tree);
}

t_rtrfd		rdr_shade(t_rtrd rdata, t_rdrtree *tree)
{
	t_rtmat	*mat;
	t_rtrfd	frag;

	if (!(rdata.lgeo.flags & RAY_GVALID))
		return (shade_sky(rdata, tree));
	mat = ((t_rtobd *)(rdata.lgeo.inst->obj))->plan.material;
	frag = shade_diffuse(rdata, mat, tree);
	// frag.hit_nor = shade_normale(&rdata, mat);
	// rdata.geo.hit_nor = frag.hit_nor;
	// // pv3fmulv3f((t_v3f *)&frag.color, shade_lightsloop(rdata.geo, tree));
	// frag.color.x = mxmaxf(mxminf(frag.color.x, 1.0f), 0.0f);
	// frag.color.y = mxmaxf(mxminf(frag.color.y, 1.0f), 0.0f);
	// frag.color.z = mxmaxf(mxminf(frag.color.z, 1.0f), 0.0f);
	// frag.color.w = mxmaxf(mxminf(frag.color.w, 1.0f), 0.0f);
	return (frag);
}
