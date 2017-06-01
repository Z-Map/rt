/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayshade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/30 09:21:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_render.h"

t_rtrfd		rdr_shade(t_rtrgd geo, t_rtree *tree)
{
	t_rtrfd	frag;

	(void)tree;
	frag = (t_rtrfd){.color = (t_rgba){42,42,42,255}, .flags = 0, .depth = INFINITY};
	if (geo.flags & RAY_GVALID)
		return (frag);
	frag.color = ((t_rtobd *)(geo.inst->obj))->plan.material->color1;
	frag.depth = geo.depth.x;
	if (geo.depth.x > 0.0f)
		frag.depth = geo.depth.y;
	frag.color.a = 255.0f * mxmaxf(1.0f - (frag.depth / 20.0f), 0.0f);
	return (frag);
}
