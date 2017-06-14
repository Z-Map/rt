/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 18:42:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_cuboid(t_rtray ray, t_rtobd *o, t_rtrgd *gd)
{
	float		dist;

	(void)o;
	dist = (gd->depth.x < 0.0) ? gd->depth.y : gd->depth.x;
	*(t_v3f *)&(gd->hit_point) = ray_hitpoint(ray, dist);
	gd->hit_point.w = dist;
	return (1);
}
