/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/29 16:20:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

// bound_raycast(&ray, obi->lbounds, gd)

static int	raycast_rnod(t_rayd *rayd, t_rtrnode *nod, t_v2f lim)
{
	t_rtray	ray;
	t_rtrgd	gd[2];
	int		(*inter)(t_rtray, t_rtobd *, t_rtrgd *);
	t_rtobi *obi;

	obi = (t_rtobi *)(nod->node.content);
	inter = obi->obj->intersect;
	gd[0] = (t_rtrgd){.flags = 0, .depth = lim.x, .hit_point = nv3f(0.0f),
		.inst = NULL, .node = NULL};
	gd[0] = (t_rtrgd){.flags = 0, .depth = lim.y, .hit_point = nv3f(0.0f),
		.inst = NULL, .node = NULL};
	if (!inter || !nod)
		return (0);
	if (!bound_raycast(&(rayd->ray), nod->lbound, gd))
		return (0);
	ray = ray_trans(rayd->ray, nod->invert_transform);
	if (inter && inter(ray, (t_rtobd *)(obi->obj), gd))
		return (1);
	return (0);
}

int			rdr_raycast(t_rayd *rayd, t_rdrtree *tree)
{
	t_rtnode	**nc;
	size_t		i;
	int			ret;
	t_v2f		lim;

	if (!rayd || !(tree->tree.node.type & TREET_RENDER) || !(tree->visible))
		return (0);
	lim = rayd->lim;
	i = tree->visible_len;
	nc = tree->visible;
	ret = 0;
	while (i--)
	{
		if (nc[i] && raycast_rnod(rayd, (t_rtrnode *)(nc[i]), lim))
			ret = 1;
	}
	return (0);
}
