/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:15:59 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_object.h"

void			object_default_cone(t_rtobd *object)
{
	object->cone.material = NULL;
	object->cone.angle = 1.0;
}

t_mat3x2f		object_bound_cone(t_rtobd *ob)
{
	t_mat3x2f       bound;

	(void)ob;
	bound.x = (t_v2f){-INFINITY, INFINITY};
	bound.y = (t_v2f){-INFINITY, INFINITY};
	bound.z = (t_v2f){-INFINITY, INFINITY};
	return (bound);
}
