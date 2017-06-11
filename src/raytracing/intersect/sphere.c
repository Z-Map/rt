/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/09 17:51:40 by qloubier         ###   ########.fr       */
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

int				intersect_sphere(t_rtray ray, t_rtobd *ob, t_rtrgd *gd)
{
	t_v2f		dist;
	int			ret;
	t_v3f		hitp[2];

	if (!calc_sphere(ob, &ray, &dist) || (dist.x > gd->depth.y)
		|| (dist.y < 0.0))
		return (0);
	ret = intersect_depth(gd, ray, dist, hitp);
	if (ret & 1)
		gd->hit_nor[0] = v3fdivv3f(hitp[0], nv3f(ob->sphere.radius));
	else if (sqrtf(hitp[0].x * hitp[0].x + hitp[0].y * hitp[0].y
		+ hitp[0].z * hitp[0].z) <= ob->sphere.radius)
		ret |= 1;
	if (ret & 2)
		gd->hit_nor[1] = v3fdivv3f(hitp[1], nv3f(ob->sphere.radius));
	else if (sqrtf(hitp[1].x * hitp[1].x + hitp[1].y * hitp[1].y
		+ hitp[1].z * hitp[1].z) <= ob->sphere.radius)
		ret |= 2;
	return (ret);
}
