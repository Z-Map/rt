/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 06:37:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "rt_render.h"
#include "rt_object.h"

void			object_default_cuboid(t_rtobd *object)
{
	object->cuboid.material = NULL;
	object->cuboid.limx = (t_v2f){-0.5f, 0.5f};
	object->cuboid.limy = (t_v2f){-0.5f, 0.5f};
	object->cuboid.limz = (t_v2f){-0.5f, 0.5f};
}

t_mat3x2f		object_bound_cuboid(t_rtobd *ob, t_mat3x2f bound)
{
	(void)ob;
	return (bound);
}
