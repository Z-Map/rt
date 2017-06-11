/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 11:00:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_render.h"
#include "rt_tools.h"

static int	depth_test(t_rtrgd geo, t_rtrgd *gd, t_rtrnode *nod)
{
	float	d;

	if (geo.depth.y < 0.0)
		return (0);
	d = (gd->depth.x < 0.0) ? gd->depth.y : gd->depth.x;
	if (geo.depth.x > d)
		return (0);
	else if ((geo.depth.x < 0.0) && (geo.depth.y > d))
		return (0);
	*gd = geo;
	gd->node = nod;
	return (1);
}

static int	intersect_obj(t_rtray ray, t_rtobi *obi, t_rtrgd *geo)
{
	int		(*inter)(t_rtray, t_rtobd *, t_rtrgd *);
	t_ul		flags;

	flags = geo->flags;
	geo->flags = 0;
	inter = obi->obj->intersect;
	if (bound_raycast(&ray, obi->lbounds, geo) && inter
		&& inter(ray, (t_rtobd *)(obi->obj), geo))
	{
		geo->ray = ray;
		geo->inst = obi;
		geo->flags = flags;
		if (geo->flags & RAY_GDEPTH0)
			geo->flags |= RAY_GHNOR0 | RAY_LOCAL0;
		if (geo->flags & RAY_GDEPTH0)
			geo->flags |= RAY_GHNOR1 | RAY_LOCAL1;
		return (1);
	}
	geo->flags = flags;
	return (0);
}

static int	raycast_rnod(t_rtray ray, t_rtrnode *nod, t_rtrgd geo, t_rtrgd *gd)
{
	int			ret;

	ret = 0;
	(void)intersect_obj;
	(void)depth_test;
	if (!nod)
		return (0);
	if (bound_raycast(&ray, nod->lbound, &geo) &&
		intersect_obj(ray_trans(ray, nod->invert_transform),
		(t_rtobi *)(nod->node.content), &geo))
		ret = depth_test(geo, gd, nod);
	return (ret);
}

t_rtrgd			rdr_raycast(t_rtray ray, t_rdrtree *tree, float lim)
{
	t_rtrgd		geo;
	t_rtrgd		gd;
	t_rtnode	**nc;
	size_t		i;

	geo = (t_rtrgd){ .flags = 0, .depth = (t_v2f){-INFINITY,
		lim}, .hit_point = nv4f(0.0f)};
	gd = (t_rtrgd){ .flags = 0, .depth = (t_v2f){lim,
		lim}, .hit_point = nv4f(0.0f)};
	if (!(tree->tree.node.type & TREET_RENDER) || !(tree->visible))
		return (gd);
	i = tree->visible_len;
	nc = tree->visible;
	while (i--)
		if (nc[i] && raycast_rnod(ray, (t_rtrnode *)(nc[i]), geo, &gd))
			gd.flags |= RAY_GVALID;
	return (gd);
}
