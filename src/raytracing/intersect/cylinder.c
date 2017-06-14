/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 15:55:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_cylinder(t_rtobd *cylinder, t_rtray *ray, t_v2f *dist)
{
	t_v3f	coef;
	float	delta;
	float	radius;

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
		delta = sqrtf(delta);
		*dist = sortv2f((t_v2f){(-coef.y + delta) / (2 * coef.x),
			(-coef.y - delta) / (2 * coef.x)});
		return (1);
	}
	return (0);
}

int				intersect_cylinder(t_rtray ray, t_rtobd *cy, t_rtrgd *gd)
{
	t_v2f		dist;
	int			ret;
	t_v3f		hitp[2];

	if (!calc_cylinder(cy, &ray, &dist))
		return (0);
	ret = intersect_depth(gd, ray, dist, hitp);
	if (!(ret & 1) && (sqrtf(hitp[0].x * hitp[0].x
		+ hitp[0].y * hitp[0].y) <= cy->cylinder.radius))
		ret |= 1;
	if (!(ret & 2) && (sqrtf(hitp[1].x * hitp[1].x
		+ hitp[1].y * hitp[1].y) <= cy->cylinder.radius))
		ret |= 2;
	return (ret);
}
