/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/06/08 19:33:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		raytrace(t_rtray ray, t_rtree *tree, t_ui depth)
{
	t_rtrgd	geo;
	t_rtrfd	frag;

	(void)depth;
	geo = rdr_raycast(ray, (t_rdrtree *)tree, INFINITY);
	frag = rdr_shade(geo_getglobal(geo, ray), tree);
	return ((t_rtrd){ .fcolor = frag.color, .fdepth = frag.depth});
}
