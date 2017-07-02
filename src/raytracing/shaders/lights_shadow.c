/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:01:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

float		get_spec(t_rtrgd geo, t_rtrld l)
{
	t_v3f	view;
	t_v3f	reflect;
	float	latt;
	float	li;

	view = geo.ray.direction;
	reflect = v3faddv3f(l.v, v3fmulv3f(nv3f(2 * (-v3fdotv3f(l.v,
		geo.hit_nor))), geo.hit_nor));
	latt = v3fdotv3f(view, reflect);
	if (latt < 0.0f)
		return (0.0f);
	li = pow(latt, 20);
	latt *= 0.6 * l.ob->pointlight.intensity;
	return (li / (1 / latt));
}

t_v4f		shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree)
{
	t_rtrd	rdata;
	t_v3f	pwr;
	t_rayd	rayd;
	t_v4f	ret;

	rayd.ray = ray_bounceto(geo, *(t_v3f *)(&l.v));
	rayd.tree = tree;
	rayd.lim = (t_v2f){0.0, l.depth};
	rayd.transmission = 0;
	rayd.reflecion = 0;
	l.color = rgbatov3f(l.ob->pointlight.color);
	rdata = shadowtrace(&rayd, l);
	pv3faddv3f(pv3fmulv3f((t_v3f *)&rdata.frag.color,
		nv3f(1.0f - rdata.frag.color.w)), v3fmulv3f(l.color,
		nv3f(rdata.frag.color.w)));
	pwr = nv3f(rdata.frag.color.w * l.pwr);
	l.i = *pv3fmulv3f((t_v3f *)&rdata.frag.color, pwr);
	ret = (t_v4f){l.i.x, l.i.y, l.i.z, get_spec(geo, l) * rdata.frag.color.w};
	return (ret);
}
