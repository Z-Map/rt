/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:02:13 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 18:45:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"
#include "generated/rt_typetab_gen.h"

void				object_default_light(t_rtobj *obj)
{
	t_rtobd			*object;

	object = (t_rtobd *)obj;
	if (obj->type & SUNLIGHT)
		object_default_sunlight(object);
	if (obj->type & POINTLIGHT)
		object_default_pointlight(object);
	if (obj->type & SPOT)
		object_default_spot(object);
}

void				object_default(t_rtobj *obj)
{
	size_t			i;
	t_rtobd			*object;

	object = (t_rtobd *)obj;
	i = obj_type_search(obj->type);
	g_obt_tab[i].init(object);
	obj->intersect = g_obt_tab[i].geometry;
	obj->get_nor= g_obt_tab[i].normal;
	obj->get_tan = g_obt_tab[i].tagentspace;
}
