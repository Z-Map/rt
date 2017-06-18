/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 18:00:26 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"

t_rtrfd		rdr_shade(t_rtrd rdata, t_rdrtree *tree)
{
	t_rtmat	*mat;
	t_rtrfd	frag;

	if (!(rdata.geo.flags & RAY_GVALID))
		return (shade_sky(rdata, tree));
	mat = ((t_rtobd *)(rdata.geo.inst->obj))->plan.material;
	frag = shade_diffuse(rdata, mat, tree);
	frag.hit_nor = shade_normale(&rdata, mat);
	rdata.geo.hit_nor = frag.hit_nor;
	pv3fmulv3f((t_v3f *)&frag.color, shade_lightsloop(rdata.geo, tree));
	return (frag);
}
