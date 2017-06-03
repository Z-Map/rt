/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:28:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 20:50:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

float	shade_sunlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	if (!nod)
		return (0.0f);
	v = geo.hit_nor[(geo.depth.x < 0.0) ? 1 : 0];
	l.depth = INFINITY;
	l.v = nod->invert_transform.z;
	l.pwr = (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	return ((l.pwr < 0.0f) ? 0.0f : shadow_test(geo, l, tree));
}

float	shade_spotlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	if (!nod)
		return (0.0f);
	v = geo.hit_nor[(geo.depth.x < 0.0) ? 1 : 0];
	l.v = normlen3f(v3fsubv3f(nod->transform.offset,
		*(t_v3f *)(&geo.hit_point)), &l.depth);
	
	l.pwr = (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	return ((l.pwr < 0.0f) ? 0.0f : shadow_test(geo, l, tree));
}

float	shade_light(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	t_v3f		v;
	t_rtrld		l;

	if (!nod)
		return (0.0f);
	v = geo.hit_nor[(geo.depth.x < 0.0) ? 1 : 0];
	l.v = normlen3f(v3fsubv3f(nod->transform.offset,
		*(t_v3f *)(&geo.hit_point)), &l.depth);
	l.pwr = (v.x * l.v.x + v.y * l.v.y + v.z * l.v.z);
	return ((l.pwr < 0.0f) ? 0.0f : shadow_test(geo, l, tree));
}
