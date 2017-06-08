/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:20:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 07:15:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"
#include "generated/rt_typetab_gen.h"
#include "rt_render.h"
#include "rt_object.h"

t_mat3x2f		instance_getbound(t_rtobi *ob, const t_mattf *m)
{
	t_mat3x2f	bound;

	bound = object_getbound(ob->obj);
	if (!m)
		m = &(ob->transform);
	ob->lbounds = bound;
	bound = bound_intersect(bound_transform(bound, *m), ob->bounds);
	if (!bound_isvalid(bound))
		bound = (t_mat3x2f){nv2f(0.0f), nv2f(0.0f), nv2f(0.0f)};
	return (bound);
}
