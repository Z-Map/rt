/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:57:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 18:06:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "generated/rt_typetab_gen.h"
#include "rt_render.h"
#include "rt_object.h"

t_mat3x2f		object_getbound(t_rtobi *ob)
{
	t_mat3x2f	bound;
	size_t		i;


	i = obj_type_search(ob->obj->type);
	bound = (t_mat3x2f){nv2f(0.0f), nv2f(0.0f), nv2f(0.0f)};
	// if (i < RT_OBT_TAB_LEN)
	// 	bound =
	bound = bound_intersect(bound, *((t_mat3x2f *)&(ob->obj->limx)));
	return (bound);
}
