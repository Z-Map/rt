/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/23 04:01:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"

t_rtrd		raytrace(t_ui x, t_ui y, t_rtrmgr *mgr, t_rtree *tree)
{
	t_rtrd	rd;
	t_rtray	ray;
	t_rtrgd	geo;

	rd = (t_rtrd){ .color = (t_rgba){42,42,42,255}, .depth = INFINITY};
	ray = rdr_pxray(x, y, mgr, (t_rtrnode *)(tree->camera));
	geo = rdr_raycast(ray, tree);
	if (geo.flags & RAY_GVALID)
	{
		rd.color = ((t_rtobd *)(geo.inst->obj))->plan.material->color1;
	}
	return (rd);
}
