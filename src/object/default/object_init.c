/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:02:13 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/14 22:14:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_light(t_rtobj *obj)
{
	t_rtobd		*object;

	object = (t_rtobd *)obj;
	if (obj->type & SUNLIGHT)
		object_default_sunlight(object);
	if (obj->type & POINTLIGHT)
		object_default_pointlight(object);
	if (obj->type & SPOT)
		object_default_spot(object);
}

void			object_default(t_rtobj *obj)
{
	t_rtobd		*object;

	object = (t_rtobd *)obj;
	if (obj->type & SCENE)
		object_default_scene(object);
	if (obj->type & EMPTY)
		object_default_empty(object);
	if (obj->type & CAMERA)
		object_default_camera(object);
	if (obj->type & (PLAN | TRIS))
		object_default_plan(object);
	if (obj->type & SPHERE)
		object_default_sphere(object);
	if (obj->type & CONE)
		object_default_cone(object);
	if (obj->type & CYLINDER)
		object_default_cylinder(object);
	if (obj->type & CUBOID)
		object_default_cuboid(object);
	if (obj->type & TRIS)
		object_default_tris(object);
	if (obj->type & (SPOT | POINTLIGHT | SUNLIGHT))
		object_default_light(obj);
}
