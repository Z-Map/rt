/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 22:51:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_cuboid(t_rtray ray, t_rtobd *o, t_rtrgd *gd)
{
	t_ul		flags;

	flags = gd->flags;
	gd->flags = 0;
	if (!bound_raycast(&ray, *((t_mat3x2f *)&(o->cuboid.sizex)), gd))
		return (0);
	if (gd->flags & RAY_GDEPTH0)
		flags |= RAY_GDEPTH0 | RAY_GHNOR0 | RAY_LOCAL0;
	if (gd->flags & RAY_GDEPTH1)
		flags |= RAY_GDEPTH1 | RAY_GHNOR1 | RAY_LOCAL1;
	gd->flags = flags;
	return (1);
}
