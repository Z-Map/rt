/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:56:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/01 02:05:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"

t_v3f			ray_hitpoint(t_rtray ray, double depth)
{
	return ((t_v3f){
		(ray.direction.x * depth) + ray.start.x,
		(ray.direction.y * depth) + ray.start.y,
		(ray.direction.z * depth) + ray.start.z,
	});
}

t_rtray			ray_trans(t_rtray ray, t_mattf m)
{
	pmattf_apply(&ray.start, &m);
	m.offset = nv3f(0.0f);
	pmattf_apply(&ray.direction, &m);
	return (ray);
}
