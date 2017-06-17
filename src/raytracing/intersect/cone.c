/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 15:25:14 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

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
	return (0);
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

static int		cone_depth(t_rtrgd *gd, t_rtray r, t_v2f d, t_v3f hp[2])
{
	int			ret;

	ret = 0;
	if (((d.y < gd->depth.y) && (d.y > gd->depth.x)) ||
		is_in_cone(hp[0].x, ray_hitpoint(r, gd->depth.y)))
		ret = 8;
	if ((gd->depth.x >= 0.0f)
		&& is_in_cone(hp[0].x, ray_hitpoint(r, gd->depth.x)))
	{
		ret = 4;
		if ((d.x > gd->depth.x) && (d.x < gd->depth.y))
			ret |= geo_setdepth(gd, 2, d.x);
	}
	else if ((gd->depth.x >= 0.0f) && (d.x < gd->depth.x) &&
		(d.y > gd->depth.x) && (d.y < gd->depth.y))
	{
			ret |= geo_setdepth(gd, 1, d.y);
			d.y = INFINITY;
	}
	else if ((d.x > gd->depth.x) && (d.x < gd->depth.y) && (ret & 8))
		ret |= geo_setdepth(gd, 1, d.x);
	if ((d.y < gd->depth.y) && (d.y > gd->depth.x))
		ret |= geo_setdepth(gd, 2, d.y);
	hp[0] = ray_hitpoint(r, gd->depth.x);
	hp[1] = ray_hitpoint(r, gd->depth.y);
	return (ret & ~8);
}

int				intersect_cone(t_rtray ray, t_rtobd *cone, t_rtrgd *gd)
{
	t_v2f		dist;
	int			ret;
	t_v3f		hp[2];

	(void)is_in_cone;
	(void)cone_depth;
	if (!calc_cone(cone, &ray, &dist) || (dist.x > gd->depth.y)
		|| (dist.y < 0.0))
		return (0);
	hp[0].x = mxabsf(cone->cone.angle) / 2;
	if (!(ret = cone_depth(gd, ray, dist, hp)))
		return (0);
	if (gd->depth.x < 0.0)
		gd->hit_point = (t_v4f){hp[1].x, hp[1].y, hp[1].z, gd->depth.y};
	else
		gd->hit_point = (t_v4f){hp[0].x, hp[0].y, hp[0].z, gd->depth.x};
	return (ret);
}
