/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 16:40:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		shadowtrace(t_rayd *rayd, t_rtrld l)
{
	t_rtrd	rdata;
	int		i;

	rdata.tree = rayd->tree;
	rdata.ray = rayd->ray;
	i = RDR_GEOSTACK;
	rdata.frag.color = (t_v4f){l.color.x, l.color.y, l.color.z, 1.0f};
	while (i--)
		rayd->geostack[i] = (t_rtrgd){.flags = 0, .depth = INFINITY};
	if (!rdr_raycast(rayd, rayd->tree))
		return (rdata);
	rdata = shadowshade(rdata, rayd->geostack[0], rayd, 0);
	return (rdata);
}

t_rtrd		raytrace(t_rayd *rayd)
{
	t_rtrd	rdata;
	int		i;

	rdata.tree = rayd->tree;
	rdata.ray = rayd->ray;
	i = RDR_GEOSTACK;
	while (i--)
		rayd->geostack[i] = (t_rtrgd){.flags = 0, .depth = INFINITY};
	if (!rdr_raycast(rayd, rayd->tree))
		return (raysky(rdata, rayd));
	rdata = rayshade(rdata, rayd->geostack[0], rayd, 0);
	return (rdata);
}
