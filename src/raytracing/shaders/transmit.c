/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:01:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/29 17:50:23 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

t_rtrd		shadow_transmit(t_rtrd rdata, t_rdrtree *tree, t_ui raycount)
{
	(void)raycount;
	(void)tree;
	return (rdata);
}

t_rtrd		rdr_transmit(t_rtrd rdata, t_rdrtree *tree, t_ui raycount)
{
	t_rtrd	trd;
	float	alpha;

	if (rdata.frag.color.w >= 1.0)
		return (rdata);
	alpha = rdata.frag.color.w;
	trd = rdata;
	trd.ray = ray_bounceto(rdata.geo, calc_refraction(rdata.lgeo));
	if (raycount)
		trd = raytrace(trd.ray, tree, raycount - 1);
	else
		trd.frag = shade_sky(rdata, tree);
	pv3fmulv3f((t_v3f *)&trd.frag.color, nv3f(1.0f - alpha));
	pv3faddv3f(pv3fmulv3f((t_v3f *)&rdata.frag.color, nv3f(alpha)),
		*(t_v3f *)(&trd.frag.color));
	rdata.frag.color.w = 1.0f;
	return (rdata);
}

t_v3f		calc_refraction(t_rtrgd gd)
{
	float	ref;
	float	n;
	float	c1;
	float	c2;
	float	coef;

	ref = ((t_rtobd *)(gd.inst->obj))->plan.material->refraction;
	if (ref != 1.0)
		ft_printf("ref = %f\n", ref);
	n = 1 / ref;
	c1 = v3fdotv3f(gd.ray.direction, gd.hit_nor);
	c2 = sqrtf(1 - ((1 * ref) * (1 * ref)) * (1.0 - (c1 * c1)));
	coef = (c1 > 0) ? -1.0f : 0.0f;
	gd.ray.direction = v3faddv3f(v3fmulv3f(nv3f(n), gd.ray.direction),
			v3fmulv3f(nv3f((n * c1) - (c2 * coef)), gd.hit_nor));
	return (gd.ray.direction);
}
