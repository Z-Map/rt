/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:04:58 by fanno             #+#    #+#             */
/*   Updated: 2017/05/14 21:44:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
