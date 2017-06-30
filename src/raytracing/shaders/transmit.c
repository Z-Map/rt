/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:01:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 15:39:30 by qloubier         ###   ########.fr       */
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
	float		alpha;
	t_v3f		col;

	alpha = mxrangef(rdata.frag.color.w, 0.0f, 1.0f);
	if (alpha >= 1.0f)
		return (rdata);
	if (num < RDR_GEOSTACK)
	{
		trd = shadowshade(rdata, rayd->geostack[num + 1], rayd, num + 1);
	}
	else
		trd.frag.color = nv4f(1.0f);
	col = *(t_v3f *)&(trd.frag.color);
	pv3faddv3f(pv3fmulv3f((t_v3f *)&(rdata.frag.color), nv3f(alpha)),
		v3fmulv3f(col, nv3f(1.0f - alpha)));
	rdata.frag.color.w *= trd.frag.color.w;
	return (rdata);
}

static t_rtrd	raytracecall(t_rtrd rdata, t_rayd *rayd, t_ui num)
{
	t_rayd		nrayd;
	float		ref;

	ref = ((t_rtobd *)(rdata.lgeo.inst->obj))->plan.material->refraction;
	if ((ref == 1.0f) && (num < RDR_GEOSTACK))
		rdata = rayshade(rdata, rayd->geostack[num + 1], rayd, num + 1);
	else if (rayd->transmission > 0)
	{
		nrayd.tree = rayd->tree;
		nrayd.ray = ray_bounceto(rdata.geo, calc_refraction(rdata.lgeo, ref));
		nrayd.transmission = rayd->transmission - 1;
		nrayd.transmission = rayd->reflecion;
		nrayd.lim = rayd->lim;
		rdata = raytrace(&nrayd);
	}
	else
		return (raysky(rdata, rayd));
	return (rdata);
}

t_rtrd			rdr_transmit(t_rtrd rdata, t_rayd *rayd, t_ui num)
{
	t_rtrd		trd;
	float		alpha;
	t_v3f		col;

	alpha = mxrangef(rdata.frag.color.w, 0.0f, 1.0f);
	if (alpha >= 1.0f)
		return (rdata);
	trd = raytracecall(rdata, rayd, num);
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

	n = 1 / ref;
	c1 = v3fdotv3f(gd.ray.direction, gd.hit_nor);
	c2 = sqrtf(1 - ((1 * ref) * (1 * ref)) * (1.0 - (c1 * c1)));
	coef = (c1 > 0) ? -1.0f : 0.0f;
	gd.ray.direction = v3faddv3f(v3fmulv3f(nv3f(n), gd.ray.direction),
			v3fmulv3f(nv3f((n * c1) - (c2 * coef)), gd.hit_nor));
	return (gd.ray.direction);
}
