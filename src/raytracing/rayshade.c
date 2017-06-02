/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 00:33:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_render.h"



t_rtrfd		rdr_shade(t_rtrgd geo, t_rtree *tree)
{
	t_rtrfd	frag;
	t_v4f	color;

	(void)tree;
	frag = (t_rtrfd){.color = (t_rgba){42,42,42,255}, .flags = 0,
		.depth = INFINITY};
	if (!(geo.flags & RAY_GVALID))
		return (frag);
	frag.color = ((t_rtobd *)(geo.inst->obj))->plan.material->color1;
	frag.depth = (float)geo.depth.x;
	if (geo.depth.x < 0.0f)
		frag.depth = (float)geo.depth.y;
	color = (t_v4f){frag.color.r, frag.color.g, frag.color.b, frag.color.a};
	return (frag);
}
