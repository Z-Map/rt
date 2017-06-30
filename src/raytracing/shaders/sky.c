/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:44:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 10:17:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"

t_rtrfd		shade_sky(t_rtrd *rdata, t_rdrtree *tree)
{
	t_rtmat	*mat;
	t_rtrfd	frag;
	t_v2f	uv;

	mat = ((t_rtobd *)(tree->tree.scene))->scene.sky;
	frag.color = rgbatov4f(mat->color1);
	uv = v2fmulv2f(v2faddv2f(nortouv(rdata->ray.direction),
		mat->diffuse.offset), mat->diffuse.size);
	if ((mat->diffuse.flags & TEX_VALID)
		&& (mat->diffuse.tex->flags & TEX_LOADED))
		frag.color = mat->diffuse.tex->getcol(mat->diffuse.tex, uv);
	frag.color.w = 1.0f;
	frag.hit_nor = v3fmulv3f(rdata->ray.direction, nv3f(-1.0f));
	frag.ndepth = INFINITY;
	return (frag);
}
