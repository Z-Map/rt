/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/06/11 23:03:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		shadowtrace(t_rtray ray, t_rtrld l, t_rdrtree *tree, t_ui raycount)
{
	t_rtrd	rdata;

	rdata.lgeo = rdr_raycast(ray, tree, l.depth);
	return (shadow_transmit(rdata, tree, raycount));
}


t_rtrd		raytrace(t_rtray ray, t_rdrtree *tree, t_ui raycount)
{
	t_rtrd	rdata;

	rdata.tree = tree;
	rdata.ray = ray;
	rdata.lgeo = rdr_raycast(ray, tree, INFINITY);
	rdata.lray = rdata.lgeo.ray;
	rdata.geo = geo_getglobal(rdata.lgeo, ray);
	rdata.frag = rdr_shade(rdata, tree);
	return (rdr_transmit(rdata, tree, raycount));
}
