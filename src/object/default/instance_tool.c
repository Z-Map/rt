/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:20:25 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:25:19 by qloubier         ###   ########.fr       */
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
	ob->bounds = bound;
	bound = bound_transform(bound, *m);
	return (bound);
}
