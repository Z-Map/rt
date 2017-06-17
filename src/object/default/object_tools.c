/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:57:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:42:52 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "generated/rt_typetab_gen.h"
#include "rt_render.h"
#include "rt_object.h"

t_mat3x2f		object_getbound(t_rtobj *obj)
{
	t_rtobd		*obd;
	t_mat3x2f	bound;
	size_t		i;

	obd = (t_rtobd *)obj;
	i = obj_type_search(obj->type);
	bound = (t_mat3x2f){nv2f(0.0f), nv2f(0.0f), nv2f(0.0f)};
	if ((i < RT_OBT_TAB_LEN) && g_obt_tab[i].bounds)
	{
		bound = g_obt_tab[i].bounds((t_rtobd *)(obj),
			*((t_mat3x2f *)(t_ul)&(obd->plan.limx)));
	}
	return (bound);
}
