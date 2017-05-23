/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/24 00:15:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

static int	intersect_obj(t_rtray ray, t_rtobi *obi, t_rtrgd *geo)
{
	int		(*inter)(t_rtray, t_rtobd *, t_rtrgd *);

	inter = obi->obj->intersect;
	if (inter && inter(ray, (t_rtobd *)(obi->obj), geo))
	{
		geo->inst = obi;
		return (1);
	}
	return (0);
}

static int	raycast_rnod(t_rtray ray, t_rtrnode *nod, t_rtrgd *geo)
{
	t_rtnode	*nc;
	t_rtrgd		ogd;
	t_rtrgd		gd;
	int			ret;

	gd = *geo;
	if (!bound_raycast(&ray, nod->bound, &gd))
		return (0);
	// RT_DBGM("glups");
	ret = 0;
	ogd = gd;
	if ((((t_rtobi *)(nod->node.content))->obj->type & VISIBLE) &&
		bound_raycast(&ray, nod->lbound, &ogd) && intersect_obj(ray_trans(ray,
		nod->invert_transform), (t_rtobi *)(nod->node.content), &ogd))
		ret = 1;
	nc = nod->node.childs;
	while (nc)
	{
		if (raycast_rnod(ray, (t_rtrnode *)nc, &gd))
			ret = 2;
		nc = nc->next;
	}
	if (ret)
		*geo = (ret == 1) ? ogd : gd;
	return (ret);
}

t_rtrgd			rdr_raycast(t_rtray ray, t_rtree *tree)
{
	t_rtrgd		geo;
	t_rtnode	*nc;

	geo = (t_rtrgd){ .flags = 0, .depth = (t_v2d){(double)-INFINITY,
		(double)INFINITY}, .hit_point = nv4f(0.0f)};
	if (tree->node.flags & TREET_RENDER)
	{
		nc = tree->node.childs;
		while (nc)
		{
			if (raycast_rnod(ray, (t_rtrnode *)nc, &geo))
				geo.flags |= RAY_GVALID;
			nc = nc->next;
		}
	}
	return (geo);
}
