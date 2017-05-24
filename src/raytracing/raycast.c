/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/24 18:18:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

static int	depth_test(t_rtrgd geo, t_rtrgd *gd)
{
	if (((geo.depth.x > 0.0) && (geo.depth.x < gd->depth.x))
		|| ((geo.depth.x < 0.0) && (geo.depth.y > 0.0)
			&& (geo.depth.y < gd->depth.y)))
	{
		*gd = geo;
		return (1);
	}
	return (0);
}

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

static int	raycast_rnod(t_rtray ray, t_rtrnode *nod, t_rtrgd geo, t_rtrgd *gd)
{
	t_rtnode	*nc;
	t_rtrgd		ogd;
	int			ret;

	ret = 0;
	if (!bound_raycast(&ray, nod->bound, &geo))
		return (0);
	ogd = geo;
	if ((((t_rtobi *)(nod->node.content))->obj->type & VISIBLE) &&
		(!(nod->node.childs) || bound_raycast(&ray, nod->lbound, &ogd)) &&
		intersect_obj(ray_trans(ray, nod->invert_transform),
		(t_rtobi *)(nod->node.content), &ogd))
		ret = depth_test(ogd, gd);
	nc = nod->node.childs;
	while (nc)
	{
		if (raycast_rnod(ray, (t_rtrnode *)nc, geo, gd))
			ret = 2;
		nc = nc->next;
	}
	return (ret);
}

t_rtrgd			rdr_raycast(t_rtray ray, t_rtree *tree)
{
	t_rtrgd		geo;
	t_rtrgd		gd;
	t_rtnode	*nc;

	geo = (t_rtrgd){ .flags = 0, .depth = (t_v2d){(double)-INFINITY,
		(double)INFINITY}, .hit_point = nv4f(0.0f)};
	gd = (t_rtrgd){ .flags = 0, .depth = (t_v2d){(double)INFINITY,
		(double)INFINITY}, .hit_point = nv4f(0.0f)};
	if (tree->node.flags & TREET_RENDER)
	{
		nc = tree->node.childs;
		while (nc)
		{
			if (raycast_rnod(ray, (t_rtrnode *)nc, geo, &gd))
				gd.flags |= RAY_GVALID;
			nc = nc->next;
		}
	}
	return (gd);
}
