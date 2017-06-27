/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 18:31:50 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/19 18:18:21 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"
#include "rt_tools.h"

/*
** nor.x *= -1.0f;
*/

t_v3f		shade_normale(t_rtrd *rdata, t_rtmat *mat)
{
	t_mattf	m;
	t_v3f	nor;
	t_v2f	uv;

	nor = rdata->geo.hit_nor;
	if (!(mat->normal.flags & TEX_VALID))
		return (nor);
	uv = v2fmulv2f(v2faddv2f(geo_uv(rdata), mat->normal.offset),
		mat->normal.size);
	nor = mat->normal.tex->getnor(mat->normal.tex, uv);
	nor.y *= -1.0f;
	m = (t_mattf){ .x = rdata->lgeo.hit_tangent.x, rdata->lgeo.hit_tangent.y,
		.z = rdata->lgeo.hit_nor, .offset = nv3f(0.0f), .w = nv4f(0.0f)};
	m.w.w = 1.0f;
	pmattf_apply(&nor, &m);
	return (nor);
}
