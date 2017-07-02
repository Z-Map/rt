/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:56:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 13:08:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"
#include "rt_tools.h"

t_v3f			ray_hitpoint(t_rtray ray, float depth)
{
	return ((t_v3f){
		(ray.direction.x * depth) + ray.start.x,
		(ray.direction.y * depth) + ray.start.y,
		(ray.direction.z * depth) + ray.start.z,
	});
}

t_rtray			ray_trans(t_rtray ray, t_mattf m)
{
	pv3faddv3f(&ray.start, m.offset);
	m.offset = nv3f(0.0f);
	pmattf_apply(&ray.start, &m);
	pmattf_apply(&ray.direction, &m);
	return (ray);
}

t_rtray			ray_bounceto(t_rtrgd gd, t_v3f dir)
{
	t_rtray		ray;

	ray.direction = dir;
	ray.start = gd.hit_point;
	ray.start = v3faddv3f(ray.start, v3fmulv3f(ray.direction, nv3f(MARGIN)));
	return (ray);
}

t_rtray			ray_transmit(t_rtrgd gd, t_v3f dir)
{
	t_rtray		ray;

	ray.direction = dir;
	ray.start = gd.hit_point;
	ray.start = v3faddv3f(ray.start, v3fmulv3f(gd.ray.direction,
		nv3f(MARGIN)));
	return (ray);
}

t_v3f			calc_reflexion(t_rtrgd gd)
{
	gd.ray.direction = v3fsubv3f(gd.ray.direction, v3fmulv3f(
		nv3f(2.0f * v3fdotv3f(gd.hit_nor, gd.ray.direction)), gd.hit_nor));
	return (gd.ray.direction);
}
