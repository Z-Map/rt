/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:21:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 20:12:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

static float	shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree)
{
	t_rtrgd	gd;
	float	a;

	gd = rdr_raycast(ray_bounceto(geo, *(t_v3f *)(&l.v)), (t_rtree *)tree);
	a = (float)(gd.depth.x < 0.0) ? gd.depth.y : gd.depth.x;
	if ((gd.flags & RAY_GVALID) && (l.depth > a))
		return (0.0f);
	return (l.pwr);
}

static float	sunlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	if (!nod)
		return (0.0f);
	v = geo.hit_nor[(geo.depth.x < 0.0) ? 1 : 0];
	l.depth = INFINITY;
	if (nod->node.content->obj->type & SUNLIGHT)
		l.v = nod->invert_transform.z;
	else
		l.v = normlen3f(v3fsubv3f(nod->transform.offset,
			*(t_v3f *)(&geo.hit_point)), &l.depth);
	l.pwr = (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	return ((l.pwr < 0.0f) ? 0.0f : shadow_test(geo, l, tree));
}

float			shade_lightsloop(t_rtrgd geo, t_rdrtree *tree)
{
	size_t		i;
	float		intensity;

	i = tree->lights_len;
	intensity = 0.0f;
	if (!i)
		return (0.0f);
	while (i--)
		intensity += sunlight(geo, (t_rtrnode *)(tree->lights[i]), tree);
	return (intensity);
}
