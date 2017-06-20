/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 11:01:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/20 14:35:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"
#include "rt_tools.h"

t_rtrfd		shade_diffuse(t_rtrd rdata, t_rtmat *mat, t_rdrtree *tree)
{
	t_rtrfd	frag;
	// t_v2f	uv;

	(void)tree;
	(void)rdata;
	frag = (t_rtrfd){nv4f(1.0f), (t_v3f){0.0f,0.0f,1.0f}, 0.0f};
	frag.color = rgbatov4f(mat->color1);
//	uv = (t_v2f){rdata.lgeo.hit_point.x + rdata.lgeo.hit_point.z,
//		rdata.lgeo.hit_point.y + rdata.lgeo.hit_point.z};
	// uv = v2fmulv2f(v2faddv2f(geo_uv(&rdata), mat->diffuse.offset),
	// 	mat->diffuse.size);
	// if (mat->diffuse.flags & TEX_VALID)
	// 	frag.color = mat->diffuse.tex->getcol(mat->diffuse.tex, uv);
	return (frag);
}
