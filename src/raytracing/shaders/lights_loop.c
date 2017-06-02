/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:21:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 14:55:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"

static float	sunlight(t_rtrgd geo, t_rtrnode *nod)
{
	t_v3f		v;
	t_v3f		lv;
	float		a;

	if (!nod)
		return (0.0f);
	v = geo.hit_nor[(geo.depth.x < 0.0) ? 1 : 0];
	if (nod->node.content->obj->type & SUNLIGHT)
		lv = nod->invert_transform.z;
	else
		lv = normalize3f(v3fsubv3f(nod->transform.offset,
			*(t_v3f *)(&geo.hit_point)));
	a = (v.x * lv.x + v.y * lv.y + v.z * lv.z);
	return ((a < 0.0f) ? 0.0f : a);
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
		intensity += sunlight(geo, (t_rtrnode *)(tree->lights[i]));
	return (intensity);
}
