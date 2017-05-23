/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:04:58 by fanno             #+#    #+#             */
/*   Updated: 2017/05/23 23:35:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"

static void		set_vec(t_v3f *vtab, int min[4], int max[4], t_v2f lim)
{
	int		i;

	i = 4;
	while (i--)
		vtab[min[i]].x = lim.x;
	i = 4;
	while (i--)
		vtab[max[i]].x = lim.y;
}

t_mat3x2f		bound_transform(t_mat3x2f b, t_mattf m)
{
	t_v3f	v[8];
	int		i;

	set_vec(v, (int[4]){0, 3, 4, 7}, (int[4]){1, 2, 5, 6}, b.x);
	set_vec((t_v3f *)((t_ul)v + 4), (int[4]){2, 3, 6, 7},
		(int[4]){0, 1, 4, 5}, b.y);
	set_vec((t_v3f *)((t_ul)v + 4), (int[4]){4, 5, 6, 7},
		(int[4]){0, 1, 2, 3}, b.z);
	i = 8;
	while (i--)
		pmattf_apply(v + i, &m);
	i = 7;
	b = (t_mat3x2f){.x = {v[7].x, v[7].x}, .y = {v[7].y, v[7].y},
		.z = {v[7].z, v[7].z}};
	while (i--)
	{
		b.x.x = mxminf(v[i].x, b.x.x);
		b.x.y = mxmaxf(v[i].x, b.x.y);
		b.y.x = mxminf(v[i].y, b.y.x);
		b.y.y = mxmaxf(v[i].y, b.y.y);
		b.z.x = mxminf(v[i].z, b.z.x);
		b.z.y = mxmaxf(v[i].z, b.z.y);
	}
	t_mat3x2f	mb = b;
	ft_printf("bounds : x[%f,%f] y[%f,%f] z[%f,%f]}\n", mb.x.x, mb.x.y, mb.y.x,
		mb.y.y, mb.z.x, mb.z.y);
	return (b);
}

static int		bound_rcdim(t_v2f rd, t_v3f nor, t_v2f b, t_rtrgd *gd)
{
	t_v2d		lim;

	if (rd.y != 0.0f)
		lim = sortv2d((t_v2d){(double)((b.x - rd.x) / rd.y),
			(double)((b.y - rd.x) / rd.y)});
	else
	{
		lim = (t_v2d){(double)(b.x - rd.x), (double)(b.y - rd.y)};
		return (((lim.x > 0.0) || (lim.y < 0.0)) ? 0 : 1);
	}
	if ((lim.y < gd->depth.x) || (lim.x > gd->depth.y))
		return (0);
	if (lim.x > gd->depth.x)
	{
		gd->depth.x = lim.x;
		gd->hit_nor[0] = (rd.y > 0.0f) ? v3fmulv3f(nor, nv3f(-1.0f)) : nor;
		gd->flags |= RAY_GDEPTH0 | RAY_GHNOR0;
	}
	if (lim.y < gd->depth.y)
	{
		gd->depth.y = lim.y;
		gd->hit_nor[1] = (rd.y > 0.0f) ? nor : v3fmulv3f(nor, nv3f(-1.0f));
		gd->flags |= RAY_GDEPTH1 | RAY_GHNOR1;
	}
	return (1);
}

int				bound_raycast(t_rtray *r, t_mat3x2f b, t_rtrgd *gd)
{
	if (!bound_rcdim((t_v2f){r->start.x, r->direction.x},
			(t_v3f){1.0f, 0.0f, 0.0f}, b.x, gd) || (gd->depth.y < 0.0))
		return (0);
	if (!bound_rcdim((t_v2f){r->start.y, r->direction.y},
			(t_v3f){0.0f, 1.0f, 0.0f}, b.y, gd) || (gd->depth.y < 0.0))
		return (0);
	if (!bound_rcdim((t_v2f){r->start.z, r->direction.z},
			(t_v3f){0.0f, 0.0f, 1.0f}, b.z, gd) || (gd->depth.y < 0.0))
		return (0);
	return (1);
}

/*
static int	rt_bounds_update_in(t_obj *obj, int mode, void *userdata)
{
	(void)userdata;
	if (mode == PREFIX)
		obj->bounds = obj->hitbox;
	else if (obj->parent)
		update_cube(&obj->parent->bounds, &obj->bounds);
	return (0);
}

void		rt_bounds_update(t_obj *node)
{
	rt_node_foreach(node, SUFFIX | PREFIX, &rt_bounds_update_in, NULL);
}
//*/
