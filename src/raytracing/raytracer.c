/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/27 04:49:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	}
	return (rd);
}
