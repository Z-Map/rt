/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 22:32:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_plan(t_rtray ray, t_rtobd *plan, t_rtrgd *gd)
{
	double		dist;

	(void)plan;
	dist = (-ray.start.z / ray.direction.z);
	if ((dist < 0.0) || (dist > gd->depth.y) || (dist < gd->depth.x))
		return (0);
	gd->depth.x = dist;
	gd->hit_nor[0] = (t_v3f){0.0, 0.0, 1.0};
	return (1);
}
