/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/27 16:06:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "rt_object.h"

void			object_default_tris(t_rtobd *object)
{
	object->plan.material = NULL;
}

t_mat3x2f		object_bound_tris(t_rtobd *ob, t_mat3x2f bound)
{
	(void)ob;
	return (bound_intersect((t_mat3x2f){nv2f(0.0f), nv2f(0.0f), nv2f(0.0f)},
		bound));
}
