/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:23:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 09:55:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"

int				intersect_cuboid(t_rayd *rayd, t_rtobd *o, t_rtrgd *gd)
{
	(void)o;
	gd[0].hit_point = ray_hitpoint(rayd->ray, gd[0].depth);
	gd[1].hit_point = ray_hitpoint(rayd->ray, gd[1].depth);
	return (ray_setgeo(rayd, gd[0]) | ray_setgeo(rayd, gd[1]));
}
