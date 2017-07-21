/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:21:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 22:52:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

static t_v4f	typelight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	if (nod->node.content->obj->type & SUNLIGHT)
		return (shade_sunlight(geo, nod, tree));
	if (nod->node.content->obj->type & SPOT)
		return (shade_spotlight(geo, nod, tree));
	return (shade_light(geo, nod, tree));
}

t_v4f			shade_lightsloop(t_rtrgd geo, t_rdrtree *tree)
{
	size_t		i;
	t_v3f		intensity;
	t_v3f		al;
	t_v4f		l;
	float		spec;

	i = tree->lights_len;
	spec = 0.0f;
	intensity = (t_v3f){.x = 0.0f, .y = 0.0f, .z = 0.0f};
	while (i--)
	{
		l = typelight(geo, (t_rtrnode *)(tree->lights[i]), tree);
		pv3faddv3f(&intensity, *((t_v3f *) & l));
		spec = mxmaxf(spec, l.w);
	}
	al = rgbatov3f(((t_rtobd *)(tree->tree.scene))->scene.ambient_light);
	intensity.x = mxmaxf(intensity.x, al.x);
	intensity.y = mxmaxf(intensity.y, al.y);
	intensity.z = mxmaxf(intensity.z, al.z);
	l = (t_v4f){intensity.x, intensity.y, intensity.z, spec};
	return (l);
}
