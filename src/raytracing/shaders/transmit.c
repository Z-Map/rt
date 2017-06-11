/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:01:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 23:01:06 by qloubier         ###   ########.fr       */
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
	trd.ray = ray_bounceto(rdata.geo, rdata.ray.direction);
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
