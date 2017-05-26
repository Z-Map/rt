/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/26 02:15:57 by qloubier         ###   ########.fr       */
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
		+ (ray->direction.z * ray->direction.z);
	coef.y = 2 * ray->start.x * ray->direction.x
		+ 2 * ray->start.z * ray->direction.z;
	coef.z = ray->start.x * ray->start.x + ray->start.z * ray->start.z
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

int				intersect_cylinder(t_rtray ray, t_rtobd *cylinder, t_rtrgd *gd)
{
	t_v2d		dist;
	int			ret;

	ret = 0;
	if (!calc_cylinder(cylinder, &ray, &dist))
		return (0);
	if ((dist.x > gd->depth.x) && (dist.x < gd->depth.y))
	{
		gd->depth.x = dist.x;
		ret = 1;
	}
	if ((dist.y < gd->depth.y) && (dist.y > gd->depth.x))
	{
		gd->depth.y = dist.y;
		ret = 1;
	}
	return (ret);
}
