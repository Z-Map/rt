/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 10:59:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

float		shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree)
{
	t_rtrgd	gd;
	float	a;

	gd = shadowtrace(ray_bounceto(geo, *(t_v3f *)(&l.v)), l, tree, 0).lgeo;
	a = (float)(gd.depth.x < 0.0) ? gd.depth.y : gd.depth.x;
	if ((gd.flags & RAY_GVALID) && (l.depth > a))
		return (0.0f);
	return (l.pwr);
}
