/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:21:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 19:02:15 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

static t_v3f	typelight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	if (nod->node.content->obj->type & SUNLIGHT)
		return (shade_sunlight(geo, nod, tree));
	if (nod->node.content->obj->type & SPOT)
		return (shade_spotlight(geo, nod, tree));
	return (shade_light(geo, nod, tree));
}

t_v3f			shade_lightsloop(t_rtrgd geo, t_rdrtree *tree)
{
	size_t		i;
	t_v3f		intensity;

	i = tree->lights_len;
	intensity = (t_v3f){.x = 0.0f, .y = 0.0f, .z = 0.0f};
	if (!i)
		return (intensity);
	while (i--)
		pv3faddv3f(&intensity,
			typelight(geo, (t_rtrnode *)(tree->lights[i]), tree));
	return (intensity);
}
