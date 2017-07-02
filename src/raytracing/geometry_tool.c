/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:56:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 13:13:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

t_mat2x3f	geo_cubic_tangentspace(t_v3f nor, t_v3f x, t_v3f y, t_v3f z)
{
	t_v3f	v;
	t_v3i	a;

	v = (t_v3f){mxabsf(nor.x), mxabsf(nor.y), mxabsf(nor.z)};
	a.x = (v.z > v.x) ? 1 : 0;
	a.y = (v.z > v.y) ? 1 : 0;
	a.z = (v.y > v.x) ? 1 : 0;
	if (a.x & a.y)
		return ((t_mat2x3f){x, (nor.z < 0.0f) ? (t_v3f){-y.x, -y.y, -y.z} : y});
	else if (!(a.x | a.z))
		return ((t_mat2x3f){z, (nor.x < 0.0f) ? (t_v3f){-y.x, -y.y, -y.z} : y});
	else
		return ((t_mat2x3f){z, (nor.y < 0.0f) ? x : (t_v3f){-x.x, -x.y, -x.z}});
}

void		geo_gnor(t_rtrd *rdata)
{
	t_rtrgd	*lgd;
	int		(*gnor)(t_rtobd *, t_rtrd *);

	lgd = &(rdata->lgeo);
	if (!(lgd->flags & RAY_GVALID) || (lgd->flags & RAY_GHNOR))
		return ;
	gnor = (int (*)(t_rtobd *, t_rtrd *))(lgd->inst->obj->get_nor);
	if (!gnor)
		return ;
	gnor((t_rtobd *)(lgd->inst->obj), rdata);
}

void		geo_tan(t_rtrd *rdata)
{
	t_rtrgd	*lgd;
	int		(*gtan)(t_rtobd *, t_rtrd *);

	lgd = &(rdata->lgeo);
	if ((lgd->flags & RAY_GHTANG) ||
		((lgd->flags & (RAY_GVALID | RAY_GHNOR)) != (RAY_GVALID | RAY_GHNOR)))
		return ;
	if (!(lgd->flags & RAY_GINTER))
	{
		rdata->lgeo.hit_tangent = geo_cubic_tangentspace(rdata->lgeo.hit_nor,
			(t_v3f){1.0, 0.0, 0.0}, (t_v3f){0.0, 1.0, 0.0},
			(t_v3f){0.0, 0.0, 1.0});
		rdata->lgeo.flags |= RAY_GHTANG;
	}
	else
	{
		gtan = (int (*)(t_rtobd *, t_rtrd *))(lgd->inst->obj->get_tan);
		if (!gtan)
			return ;
		gtan((t_rtobd *)(lgd->inst->obj), rdata);
	}
}

t_v2f		geo_uv(t_rtrd *rd)
{
	t_v2f	uv;
	t_ul	type;

	type = rd->lgeo.inst->obj->type;
	uv = (t_v2f){0.0f, 0.0f};
	if (!(rd->lgeo.flags & RAY_GLOCAL))
		uv = getuv_cuboid(rd->geo);
	else if ((type & (CUBOID | PLAN | CONE)) || !(rd->lgeo.flags & RAY_GINTER))
		uv = getuv_cuboid(rd->lgeo);
	else if (type & SPHERE)
		uv = getuv_sphere(rd->lgeo);
	else if (type & CYLINDER)
		uv = getuv_cylinder(rd->lgeo);
	return (uv);
}

t_v3f		calc_refraction(t_rtrgd gd, float ref)
{
	float	n;
	float	c1;
	float	c2;
	float	coef;

	n = 1.0f / ref;
	c1 = v3fdotv3f(gd.hit_nor, gd.ray.direction);
	c2 = sqrtf(1.0f - (n * n) * (1.0f - (c1 * c1)));
	coef = (c1 > 0.0) ? -1.0f : 1.0f;
	return (v3faddv3f(v3fmulv3f(nv3f(n), gd.ray.direction),
			v3fmulv3f(nv3f((n * c1) + (c2 * coef)), gd.hit_nor)));
}
