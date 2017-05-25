/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 17:37:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"
#include "rt_object.h"

void			object_default_sphere(t_rtobd *object)
{
	object->sphere.material = NULL;
	object->sphere.radius = 1.0;
}

t_mat3x2f               object_bound_sphere(t_rtobd *ob)
{
        t_mat3x2f       bound;

        bound.x = (t_v2f){-(ob->sphere.radius / 2), ob->sphere.radius / 2};
        bound.y = (t_v2f){-(ob->sphere.radius / 2), ob->sphere.radius / 2};
        bound.z = (t_v2f){-(ob->sphere.radius / 2), ob->sphere.radius / 2};
        return (bound);
}
