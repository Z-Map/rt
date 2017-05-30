/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/31 01:04:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"
#include "rt_object.h"

void			object_default_cone(t_rtobd *object)
{
	object->cone.material = NULL;
	object->cone.angle = 1.0;
}

t_mat3x2f		object_bound_cone(t_rtobd *ob, t_mat3x2f bound)
{
	float		a;

	(void)ob;
	a = mxmaxf(mxabsf(bound.z.x), mxabsf(bound.z.y));
	if (a != INFINITY)
		a = (a / cosf(ob->cone.angle / 2)) * sinf(ob->cone.angle / 2) + 0.01;
	bound = bound_intersect((t_mat3x2f){(t_v2f){-a, a}, (t_v2f){-a, a},
		(t_v2f){bound.z.x, bound.z.y}}, bound);
	return (bound);
}
