/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 09:18:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_sphere(t_rtobd *ob, t_rtray *ray, t_v2f *dist)
{
	t_v3f	coef;
	float	delta;

	coef.x = (ray->direction.x * ray->direction.x) + (ray->direction.y
		* ray->direction.y) + (ray->direction.z * ray->direction.z);
	coef.y = 2 * (ray->direction.x * ray->start.x + ray->direction.y
		* ray->start.y + ray->direction.z * ray->start.z);
	coef.z = ray->start.x * ray->start.x + ray->start.y
		* ray->start.y + ray->start.z * ray->start.z
		- ob->sphere.radius * ob->sphere.radius;
	delta = coef.y * coef.y - 4 * coef.x * coef.z;
	if (delta >= 0)
	{
		delta = sqrtf(delta);
		*dist = sortv2f((t_v2f){(-coef.y + delta) / (2 * coef.x),
			(-coef.y - delta) / (2 * coef.x)});
		return (1);
	}
	return (0);
}

int				intersect_sphere(t_rayd *rayd, t_rtobd *ob, t_rtrgd *gd)
{
	t_v2f		dist;
	int			ret;
	int			dim;
	t_v3f		hitp[2];

	ret = 0;
	if (!calc_sphere(ob, &(rayd->ray), &dist) || (dist.x > gd[1].depth)
		|| (dist.y < 0.0))
		return (0);
	dim = intersect_depth(gd, rayd->ray, dist);
	hitp[0] = gd[0].hit_point;
	hitp[1] = gd[1].hit_point;
	if ((dim & 1) || (sqrtf(hitp[0].x * hitp[0].x + hitp[0].y * hitp[0].y
		+ hitp[0].z * hitp[0].z) <= ob->sphere.radius))
		ret |= ray_setgeo(rayd, gd[0]);
	if ((dim & 2) || sqrtf(hitp[1].x * hitp[1].x + hitp[1].y * hitp[1].y
		+ hitp[1].z * hitp[1].z) <= ob->sphere.radius)
		ret |= ray_setgeo(rayd, gd[1]);
	return (ret);
}
