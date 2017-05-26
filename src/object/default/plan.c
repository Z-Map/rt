/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:11:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_object.h"

void			object_default_plan(t_rtobd *object)
{
	object->plan.material = NULL;
}

t_mat3x2f               object_bound_plan(t_rtobd *ob)
{
	t_mat3x2f       bound;

	(void)ob;
	bound.x = (t_v2f){-INFINITY, INFINITY};
	bound.y = (t_v2f){-INFINITY, INFINITY};
	bound.z = (t_v2f){-0.0001, 0.0001};
	return (bound);
}
