/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:21:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 22:56:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

static float	typelight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree)
{
	if (nod->node.content->obj->type & SUNLIGHT)
		return (shade_sunlight(geo, nod, tree));
	if (nod->node.content->obj->type & SPOT)
		return (shade_spotlight(geo, nod, tree));
	return (shade_light(geo, nod, tree));
}

float			shade_lightsloop(t_rtrgd geo, t_rdrtree *tree)
{
	size_t		i;
	float		intensity;

	i = tree->lights_len;
	intensity = 0.0f;
	if (!i)
		return (0.0f);
	while (i--)
		intensity += typelight(geo, (t_rtrnode *)(tree->lights[i]), tree);
	return (intensity);
}
