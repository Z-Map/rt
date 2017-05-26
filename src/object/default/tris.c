/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:28:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_tris(t_rtobd *object)
{
	object->plan.material = NULL;
}

t_mat3x2f		object_bound_tris(t_rtobd *ob)
{
	(void)ob;
	return ((t_mat3x2f){nv2f(0.0f), nv2f(0.0f), nv2f(0.0f)});
}
