/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 16:02:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"
#include "rt_object.h"


void			object_default_cylinder(t_rtobd *object)
{
	object->cylinder.material = NULL;
	object->cylinder.radius = 1;
}

t_mat3x2f		object_bound_cylinder(t_rtobd *ob, t_mat3x2f bound)
{
	bound = bound_intersect((t_mat3x2f){
		(t_v2f){-(ob->cylinder.radius), ob->cylinder.radius},
		(t_v2f){-(ob->cylinder.radius), ob->cylinder.radius},
		(t_v2f){-INFINITY,INFINITY}}, bound);
	return (bound);
}
