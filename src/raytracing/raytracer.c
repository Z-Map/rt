/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/27 16:48:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_render.h"

t_rtrd		raytrace(t_ui x, t_ui y, t_rtrmgr *mgr, t_rtree *tree)
{
	t_rtrd	rd;
	t_rtray	ray;
	t_rtrgd	geo;

	rd = (t_rtrd){ .fcolor = (t_rgba){42,42,42,255}, .fdepth = INFINITY};
	ray = rdr_pxray(x, y, mgr, (t_rtrnode *)(tree->camera));
	geo = rdr_raycast(ray, tree);
	if (geo.flags & RAY_GVALID)
	{
		rd.fcolor = ((t_rtobd *)(geo.inst->obj))->plan.material->color1;
		if (geo.depth.x > 0.0f)
			rd.fcolor.a = 255.0f * mxmaxf(1.0f - (geo.depth.x / 20.0f), 0.0f);
		else
			rd.fcolor.a = 255.0f * mxmaxf(1.0f - (geo.depth.y / 20.0f), 0.0f);
	}
	return (rd);
}
