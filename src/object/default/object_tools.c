/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:57:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:54:07 by qloubier         ###   ########.fr       */
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
		bound = g_obt_tab[i].bounds((t_rtobd *)(obj));
		bound = bound_intersect(bound, *((t_mat3x2f *)&(obd->plan.limx)));
		t_mat3x2f	mb = *((t_mat3x2f *)&(obd->plan.limx));
		ft_printf("bounds : x[%f,%f] y[%f,%f] z[%f,%f]}\n", (double)mb.x.x,
			(double)mb.x.y, (double)mb.y.x, (double)mb.y.y, (double)mb.z.x, mb.z.y);
	}
	return (bound);
}
