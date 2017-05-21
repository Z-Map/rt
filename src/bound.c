/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:04:58 by fanno             #+#    #+#             */
/*   Updated: 2017/05/21 04:07:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"

static void	set_vec(t_v3f *vtab, int min[4], int max[4], t_v2f lim)
{
	int		i;

	i = 4;
	while (i--)
		vtab[min[i]].x = lim.x;
	i = 4;
	while (i--)
		vtab[max[i]].x = lim.y;
}

t_mat3x2f	bound_transform(t_mat3x2f b, t_mattf m)
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
	while (i--) {
		b.x.x = mxminf(v[i].x, b.x.x);
		b.x.y = mxmaxf(v[i].x, b.x.y);
		b.y.x = mxminf(v[i].y, b.y.x);
		b.y.y = mxmaxf(v[i].y, b.y.y);
		b.z.x = mxminf(v[i].z, b.z.x);
		b.z.y = mxmaxf(v[i].z, b.z.y);
	}
	return (b);
}

int			bound_isvalid(t_mat3x2f b)
{
	if ((b.x.x > b.x.y) || (b.y.x > b.y.y) || (b.z.x > b.z.y))
		return (0);
	return (1);
}

t_mat3x2f	bound_union(t_mat3x2f a, t_mat3x2f b)
{
	a.x.x = mxminf(a.x.x, b.x.x);
	a.y.x = mxminf(a.y.x, b.y.x);
	a.z.x = mxminf(a.z.x, b.z.x);
	a.x.y = mxmaxf(a.x.y, b.x.y);
	a.y.y = mxmaxf(a.y.y, b.y.y);
	a.z.y = mxmaxf(a.z.y, b.z.y);
	return (a);
}

t_mat3x2f	bound_intersect(t_mat3x2f a, t_mat3x2f b)
{
	a.x.x = mxmaxf(a.x.x, b.x.x);
	a.y.x = mxmaxf(a.y.x, b.y.x);
	a.z.x = mxmaxf(a.z.x, b.z.x);
	a.x.y = mxminf(a.x.y, b.x.y);
	a.y.y = mxminf(a.y.y, b.y.y);
	a.z.y = mxminf(a.z.y, b.z.y);
	if (bound_isvalid(a))
		return (a);
	return (no_bound());
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
