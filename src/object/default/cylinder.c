/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 17:37:15 by qloubier         ###   ########.fr       */
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

t_mat3x2f               object_bound_cylinder(t_rtobd *ob)
{
        t_mat3x2f       bound;

        bound.x = (t_v2f){-(ob->cylinder.radius / 2), ob->cylinder.radius / 2};
        bound.y = (t_v2f){-INFINITY, INFINITY};
        bound.z = (t_v2f){-(ob->cylinder.radius / 2), ob->cylinder.radius / 2};
        return (bound);
}

