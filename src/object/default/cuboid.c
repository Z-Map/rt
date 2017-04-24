/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 01:59:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_cuboid(t_rtobj *object)
{
	object->data.cuboid = (struct s_rtcuboid){
		.material = NULL, .radius = 1.0};
}
