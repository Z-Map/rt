/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 22:34:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"
#include "rt_object.h"

void			object_default_cuboid(t_rtobd *object)
{
	object->cuboid.material = NULL;
	object->cuboid.sizex = (t_v2f){-0.5f, 0.5f};
	object->cuboid.sizey = (t_v2f){-0.5f, 0.5f};
	object->cuboid.sizez = (t_v2f){-0.5f, 0.5f};
	object->cuboid.intersect = &intersect_cuboid;
}
