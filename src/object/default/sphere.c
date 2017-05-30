/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 16:06:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "rt_render.h"
#include "rt_object.h"

void			object_default_sphere(t_rtobd *object)
{
	object->sphere.material = NULL;
	object->sphere.radius = 1.0;
}

t_mat3x2f		object_bound_sphere(t_rtobd *ob, t_mat3x2f bound)
{
	bound = bound_intersect((t_mat3x2f){(t_v2f){-(ob->sphere.radius),
		ob->sphere.radius}, (t_v2f){-(ob->sphere.radius), ob->sphere.radius},
		(t_v2f){-(ob->sphere.radius), ob->sphere.radius}}, bound);
	return (bound);
}
