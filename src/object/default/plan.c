/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 15:31:17 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_tools.h"
#include "rt_render.h"
#include "rt_object.h"

void					object_default_plan(t_rtobd *object)
{
	object->plan.material = NULL;
}

t_mat3x2f				object_bound_plan(t_rtobd *ob, t_mat3x2f bound)
{
	(void)ob;
	bound = bound_intersect((t_mat3x2f){(t_v2f){-INFINITY, INFINITY},
		(t_v2f){-INFINITY, INFINITY}, (t_v2f){-0.0001, 0.0001}}, bound);
	return (bound);
}
