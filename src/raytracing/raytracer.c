/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/06/02 14:01:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		raytrace(t_ui x, t_ui y, t_rtrmgr *mgr, t_rtree *tree)
{
	t_rtray	ray;
	t_rtrgd	geo;
	t_rtrfd	frag;

	ray = rdr_pxray(x, y, mgr, (t_rtrnode *)(tree->camera));
	geo = rdr_raycast(ray, tree);
	frag = rdr_shade(geo_getglobal(geo, ray), tree);
	return ((t_rtrd){ .fcolor = frag.color, .fdepth = frag.depth});
}
