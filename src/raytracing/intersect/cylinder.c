/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 05:09:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_cylinder(t_rtobd *cylinder, t_rtray *ray, t_v2d *dist)
{
	t_v3d	coef;
	double	delta;
	double	radius;

	radius = cylinder->cylinder.radius;
	coef.x = (ray->direction.x * ray->direction.x)
		+ (ray->direction.y * ray->direction.y);
	coef.y = 2 * ray->start.x * ray->direction.x
		+ 2 * ray->start.y * ray->direction.y;
	coef.z = ray->start.x * ray->start.x + ray->start.y * ray->start.y
		- radius * radius;
	delta = (coef.y * coef.y) - (4 * coef.x * coef.z);
	if (delta >= 0)
	{
		delta = sqrt(delta);
		*dist = sortv2d((t_v2d){(-coef.y + delta) / (2 * coef.x),
			(-coef.y - delta) / (2 * coef.x)});
		return (1);
	}
	return (0);
}

int				intersect_cylinder(t_rtray ray, t_rtobd *cy, t_rtrgd *gd)
{
	t_v2d		dist;
	int			ret;
	t_v3f		hitp[2];

	if (!calc_cylinder(cy, &ray, &dist))
		return (0);
	ret = intersect_depth(gd, ray, dist, hitp);
	if (ret & 1)
		gd->hit_nor[0] = normalize3f((t_v3f){hitp[0].x, hitp[0].y, 0.0});
	else if (sqrtf(hitp[0].x * hitp[0].x
		+ hitp[0].y * hitp[0].y) <= cy->cylinder.radius)
		ret |= 1;
	if (ret & 2)
		gd->hit_nor[1] = normalize3f((t_v3f){hitp[1].x, hitp[1].y, 0.0});
	else if (sqrtf(hitp[1].x * hitp[1].x
		+ hitp[1].y * hitp[1].y) <= cy->cylinder.radius)
		ret |= 2;
	return (ret);
}
