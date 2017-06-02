/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 13:34:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"

t_rtrfd		rdr_shade(t_rtrgd geo, t_rtree *tree)
{
	t_rtrfd	frag;
	t_v3f	color;

	(void)tree;
	frag = (t_rtrfd){.color = (t_rgba){42,42,42,255}, .flags = 0,
		.depth = INFINITY};
	if (!(geo.flags & RAY_GVALID))
		return (frag);
	frag.color = ((t_rtobd *)(geo.inst->obj))->plan.material->color1;
	frag.depth = (float)geo.depth.x;
	if (geo.depth.x < 0.0f)
		frag.depth = (float)geo.depth.y;
	color = (t_v3f){frag.color.r, frag.color.g, frag.color.b};
	color = v3fmulv3f(color, nv3f(mxmaxf(
		shade_lightsloop(geo, (t_rdrtree *)tree), 0.1f)));
	frag.color.r = (t_uc)mxminf(color.x, 255.0f);
	frag.color.g = (t_uc)mxminf(color.y, 255.0f);
	frag.color.b = (t_uc)mxminf(color.z, 255.0f);
	return (frag);
}
