/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 09:17:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_plan(t_rayd *rayd, t_rtobd *plan, t_rtrgd *gd)
{
	float		dist;

	(void)plan;
	dist = (-rayd->ray.start.z / rayd->ray.direction.z);
	if ((dist < 0.0) || (dist > gd[1].depth) || (dist < gd[0].depth))
		return (0);
	geo_setdepth(gd, 1, dist);
	gd->hit_point = ray_hitpoint(rayd->ray, dist);
	return (ray_setgeo(rayd, gd[0]));
}
