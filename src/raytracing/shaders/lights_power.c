/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:28:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 22:35:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

t_v4f			shade_sunlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	l.ob = (t_rtobd *)(nod->node.content->obj);
	if (!nod)
		return (nv4f(0.0f));
	v = geo.hit_nor;
	l.depth = INFINITY;
	l.v = nod->invert_transform.z;
	l.pwr = (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	l.pwr *= l.ob->pointlight.intensity;
	return ((l.pwr < 0.0f) ? nv4f(0.0f) : shadow_test(geo, l, tree));
}

t_v4f			shade_spotlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;
	float		a;

	l.ob = (t_rtobd *)(nod->node.content->obj);
	if (!nod)
		return (nv4f(0.0f));
	l.v = normlen3f(v3fsubv3f(nod->transform.offset,
		*(t_v3f *)(&geo.hit_point)), &l.depth);
	l.pwr = 1.0f;
	if (l.ob->pointlight.radius > 0.0)
		l.pwr = mxmaxf(1.0f - (l.depth / l.ob->pointlight.radius), 0.0f);
	v = geo.hit_nor;
	a = cosf(((l.ob->spot.angle / 180) * M_PI) / 2);
	l.pwr *= (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	l.pwr = (l.pwr < 0.0f) ? 0.0f : l.pwr;
	v = nod->transform.z;
	l.pwr *= ((v.x * l.v.x + v.y * l.v.y + v.z * l.v.z) - a) / (1.0f - a);
	l.pwr *= l.ob->pointlight.intensity;
	return ((l.pwr < 0.0f) ? nv4f(0.0f) : shadow_test(geo, l, tree));
}

t_v4f			shade_light(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	l.ob = (t_rtobd *)(nod->node.content->obj);
	if (!nod)
		return (nv4f(0.0f));
	l.v = normlen3f(v3fsubv3f(nod->transform.offset,
		*(t_v3f *)(&geo.hit_point)), &l.depth);
	l.pwr = 1.0f;
	if (l.ob->pointlight.radius > 0.0)
		l.pwr = mxmaxf(1.0f - (l.depth / l.ob->pointlight.radius), 0.0f);
	v = geo.hit_nor;
	l.pwr *= (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	l.pwr *= l.ob->pointlight.intensity;
	return ((l.pwr < 0.0f) ? nv4f(0.0f) : shadow_test(geo, l, tree));
}
