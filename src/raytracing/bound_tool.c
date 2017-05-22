/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 03:57:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/22 15:45:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"

t_mat3x2f			no_bound(void)
{
	return ((t_mat3x2f){.x = {INFINITY, -INFINITY},
		.y = {INFINITY, -INFINITY}, .z = {INFINITY, -INFINITY}});
}

int					bound_isvalid(t_mat3x2f b)
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
