/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 09:56:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_cone_ret(t_v3f coef, float delta, t_v2f *dist)
{
	if (delta > 0.0f)
	{
		delta = sqrtf(delta);
		*dist = sortv2f((t_v2f){(-coef.y - delta) / coef.x,
			(-coef.y + delta) / coef.x});
		return (1);
	}
	else if (delta == 0.0f)
		*dist = sortv2f((t_v2f){(-coef.y - delta) / coef.x,
			(-coef.y - delta) / coef.x});
	else
		return (0);
	return (1);
}

static int		calc_cone(t_rtobd *cone, t_rtray *ray, t_v2f *dist)
{
	t_v3f	coef;
	float	delta;
	float	angle;

	angle = tanf(cone->cone.angle / 2.0f);
	angle = angle * angle;
	coef.x = (ray->direction.x * ray->direction.x)
		+ (ray->direction.y * ray->direction.y)
		- (angle * (ray->direction.z * ray->direction.z));
	coef.y = 2 * (ray->start.x * ray->direction.x + ray->start.y
		* ray->direction.y - (angle * ray->direction.z * ray->start.z));
	coef.z = (ray->start.x * ray->start.x) + (ray->start.y * ray->start.y)
		- (angle * (ray->start.z * ray->start.z));
	delta = (coef.y * coef.y) - (4 * coef.x * coef.z);
	coef.x *= 2;
	return (calc_cone_ret(coef, delta, dist));
}

static int		is_in_cone(float da, t_v3f hitp)
{
	const float	c = cosf(da);
	const float	s = sinf(da);
	const float	nor = sqrtf(hitp.x * hitp.x + hitp.y * hitp.y);

	if ((c != 0.0) && (nor < ((mxabsf(hitp.z) / c) * s)))
		return (1);
	return (0);
}

static int		cone_depth(t_rtrgd *gd, t_rayd *rayd, t_v2f d, float a)
{
	int			ret;
	t_rtray		r;

	ret = 0;
	r = rayd->ray;
	if (gd[0].depth > -INFINITY)
	{
		gd[0].hit_point = ray_hitpoint(r, gd[0].depth);
		if (is_in_cone(a, gd[0].hit_point))
			ret |= ray_setgeo(rayd, gd[0]);
	}
	if (gd[1].depth < INFINITY)
	{
		gd[1].hit_point = ray_hitpoint(r, gd[1].depth);
		if (is_in_cone(a, ray_hitpoint(r, gd[1].depth)))
			ret |= ray_setgeo(rayd, gd[1]);
	}
	if ((d.x > gd[0].depth) && (d.x < gd[1].depth) && (ret & 8))
		ret |= geo_setdepth(gd, 2, d.x);
	if ((d.y < gd[1].depth) && (d.y > gd[0].depth))
		ret |= geo_setdepth(gd, 4, d.y);
	return (ret);
}

int				intersect_cone(t_rayd *rayd, t_rtobd *cone, t_rtrgd *gd)
{
	t_v2f		dist;
	int			ret;

	if (!calc_cone(cone, &(rayd->ray), &dist) || (dist.x > gd[1].depth)
		|| (dist.y < 0.0))
		return (0);
	if (!(ret = cone_depth(gd, rayd, dist, mxabsf(cone->cone.angle) / 2)))
		return (0);
	if (ret & 2)
	{
		gd[0].hit_point = ray_hitpoint(rayd->ray, gd[0].depth);
		ret |= ray_setgeo(rayd, gd[0]);
	}
	if (ret & 4)
	{
		gd[1].hit_point = ray_hitpoint(rayd->ray, gd[1].depth);
		ret |= ray_setgeo(rayd, gd[1]);
	}
	return (ret & 1);
}
