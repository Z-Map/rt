/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/24 21:31:11 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_cone(t_rtobd *cone, t_rtray *ray, t_v2d *dist)
{
	t_v3d	coef;
	double	delta;
	double	angle;

	angle = pow(tan(cone->cone.angle), 2);
	coef.x = (ray->direction.x * ray->direction.x) 
		+ (ray->direction.z * ray->direction.z)
		- angle * (ray->direction.y * ray->direction.y);
	coef.y = (2 * (ray->start.x * ray->direction.x + ray->start.z
		* ray->direction.z) - 2 * angle * ray->start.y * ray->direction.y);   
	coef.z = (ray->start.x * ray->start.x) + (ray->start.z * ray->start.z)
		- angle * (ray->start.y * ray->start.y);
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

int				intersect_cone(t_rtray ray, t_rtobd *cone, t_rtrgd *gd)
{
	t_v2d		dist;
	int			ret;

	if (!calc_cone(cone, &ray, &dist) || (dist.x > gd->depth.y)
		|| (dist.y < 0.0))
		return (0);
	ret = 0;
	if (dist.x > gd->depth.x)
	{
		gd->depth.x = dist.x;
		ret = 1;
	}
	if (dist.y < gd->depth.y)
	{
		gd->depth.y = dist.y;
		ret = 1;
	}
	return (ret);
}
