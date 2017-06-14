/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 18:39:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_plan(t_rtray ray, t_rtobd *plan, t_rtrgd *gd)
{
	float		dist;

	(void)plan;
	dist = (-ray.start.z / ray.direction.z);
	if ((dist < 0.0) || (dist > gd->depth.y) || (dist < gd->depth.x))
		return (0);
	geo_setdepth(gd, 3, dist);
	gd->depth.y = dist;
	*(t_v3f *)&(gd->hit_point) = ray_hitpoint(ray, dist);
	gd->hit_point.w = dist;
	return (1);
}
