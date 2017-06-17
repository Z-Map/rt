/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 18:31:50 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 19:08:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

t_v3f		shade_normale(t_rtrd *rdata, t_rtmat *mat)
{
	t_mattf	m;
	t_v3f	nor;
	t_v2f	uv;

	nor = rdata->geo.hit_nor;
	if (!(mat->normal.flags & TEX_VALID))
		return (nor);
	uv = v2fmulv2f(v2faddv2f((t_v2f){rdata->lgeo.hit_point.x
		+ rdata->lgeo.hit_point.z, rdata->lgeo.hit_point.y
		+ rdata->lgeo.hit_point.z}, mat->normal.offset), mat->normal.size);
	nor = mat->normal.tex->getnor(mat->normal.tex, uv);
	// nor.x *= 1.0f;
	nor.y *= -1.0f;
	m = (t_mattf){ .x = rdata->lgeo.hit_tangent.x, rdata->lgeo.hit_tangent.y,
		.z = rdata->lgeo.hit_nor, .offset = nv3f(0.0f), .w = nv4f(0.0f)};
	m.w.w = 1.0f;
	pmattf_apply(&nor, &m);
	return (nor);
}
