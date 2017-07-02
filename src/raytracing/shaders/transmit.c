/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:01:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 09:24:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd			shadow_transmit(t_rtrd rdata, t_rayd *rayd, t_ui num)
{
	t_rtrd		trd;
	t_v3f		col;
	float		a;

	a = mxrangef(rdata.frag.color.w, 0.0f, 1.0f);
	rdata.frag.color.w = 1.0f - rdata.frag.color.w;
	if (a >= 1.0f)
		return (rdata);
	if (num < RDR_GEOSTACK)
	{
		trd = shadowshade(rdata, rayd->geostack[num + 1], rayd, num + 1);
	}
	else
		trd.frag.color = nv4f(1.0f);
	col = *(t_v3f *)&(trd.frag.color);
	pv3faddv3f(pv3fmulv3f((t_v3f *)&(rdata.frag.color), nv3f(a)),
		v3fmulv3f(col, nv3f(1.0f - a)));
	rdata.frag.color.w *= trd.frag.color.w;
	return (rdata);
}

static t_rtrd	raytracecall(t_rtrd rdata, t_rayd *rayd, float ref)
{
	t_rayd		nrayd;

	nrayd.tree = rayd->tree;
	nrayd.ray = ray_bounceto(rdata.geo, calc_refraction(rdata.geo, ref));
	nrayd.transmission = rayd->transmission - 1;
	nrayd.reflecion = rayd->reflecion;
	nrayd.lim = rayd->lim;
	return (raytrace(&nrayd));
}

t_rtrd			rdr_transmit(t_rtrd rdata, t_rayd *rayd, t_ui num)
{
	t_rtrd		trd;
	float		alpha;
	t_v3f		col;
	float		ref;

	alpha = mxrangef(rdata.frag.color.w, 0.0f, 1.0f);
	if (alpha >= 1.0f)
		return (rdata);
	ref = ((t_rtobd *)(rdata.lgeo.inst->obj))->plan.material->refraction;
	if ((ref == 1.0f) && (num < RDR_GEOSTACK))
		trd = rayshade(rdata, rayd->geostack[num + 1], rayd, num + 1);
	else if (rayd->transmission > 0)
		trd = raytracecall(rdata, rayd, ref);
	else
		trd = raysky(rdata, rayd);
	col = *(t_v3f *)&(trd.frag.color);
	pv3faddv3f(pv3fmulv3f((t_v3f *)&(rdata.frag.color), nv3f(alpha)),
		v3fmulv3f(col, nv3f(1.0f - alpha)));
	rdata.frag.color.w = 1.0f;
	return (rdata);
}

t_v3f			calc_refraction(t_rtrgd gd, float ref)
{
	float		n;
	float		c1;
	float		c2;
	float		coef;

	n = 1.0f / ref;
	c1 = v3fdotv3f(gd.hit_nor, gd.ray.direction);
	c2 = sqrtf(1.0f - (n*n) * (1.0f - (c1 * c1)));
	coef = (c1 > 0.0) ? -1.0f : 1.0f;
	return (v3faddv3f(v3fmulv3f(nv3f(n), gd.ray.direction),
			v3fmulv3f(nv3f((n * c1) + (c2 * coef)), gd.hit_nor)));
}
