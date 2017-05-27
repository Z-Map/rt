/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 06:41:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

static int		calc_cone(t_rtobd *cone, t_rtray *ray, t_v2d *dist)
{
	t_v3d	coef;
	double	delta;
	double	angle;

	angle = pow(tan(cone->cone.angle), 2);
	coef.x = (ray->direction.x * ray->direction.x)
		+ (ray->direction.y * ray->direction.y)
		- angle * (ray->direction.z * ray->direction.z);
	coef.y = (2 * (ray->start.x * ray->direction.x + ray->start.y
		* ray->direction.y) - 2 * angle * ray->start.z * ray->direction.z);
	coef.z = (ray->start.x * ray->start.x) + (ray->start.y * ray->start.y)
		- angle * (ray->start.z * ray->start.z);
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

static int		is_in_cone(float da, t_v3f hitp)
{
	const float	nor = sqrtf(hitp.x * hitp.x + hitp.y * hitp.y);

	da = tanf(da * 2);
	if (nor <= (hitp.z * hitp.z * da))
		return (1);
	return (0);
}

int				intersect_cone(t_rtray ray, t_rtobd *cone, t_rtrgd *gd)
{
	t_v2d		dist;
	int			ret;
	t_v3f		hitp[2];
	float		a;

	a = mxabsf(cone->cone.angle) / 2;
	if (!calc_cone(cone, &ray, &dist) || (dist.x > gd->depth.y)
		|| (dist.y < 0.0))
		return (0);
	ret = intersect_depth(gd, ray, dist, hitp);
	if (ret & 1)
		gd->hit_nor[0] = v3faddv3f(v3fdivv3f(normalize3f((t_v3f){hitp[0].x,
			hitp[0].y, 0.0}), nv3f(cosf(a))), (t_v3f){0.0f, 0.0f,
			((hitp[0].z < 0.0) ? 1.0f : -1.0f) * sinf(a)});
	else if (is_in_cone(a, hitp[0]))
		ret |= 1;
	if (ret & 2)
		gd->hit_nor[1] = v3faddv3f(v3fdivv3f(normalize3f((t_v3f){hitp[1].x,
			hitp[1].y, 0.0}), nv3f(cosf(a))), (t_v3f){0.0f, 0.0f,
			((hitp[1].z < 0.0) ? 1.0f : -1.0f) * sinf(a)});
	else if (is_in_cone(a, hitp[1]))
		ret |= 2;
	return (ret);
}
