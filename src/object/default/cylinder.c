/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 04:52:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_object.h"


void			object_default_cylinder(t_rtobd *object)
{
	object->cylinder.material = NULL;
	object->cylinder.radius = 1;
}

t_mat3x2f		object_bound_cylinder(t_rtobd *ob)
{
	t_mat3x2f       bound;

	bound.x = (t_v2f){-(ob->cylinder.radius) - 0.0001f,
		ob->cylinder.radius + 0.0001f};
	bound.y = (t_v2f){-(ob->cylinder.radius) - 0.0001f,
		ob->cylinder.radius + 0.0001f};
	bound.z = (t_v2f){-INFINITY,INFINITY};
	return (bound);
}
