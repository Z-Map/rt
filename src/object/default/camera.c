/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:14 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:01:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_camera(t_rtobj *object)
{
	object->data.camera = (struct s_rtcamera){
		.fov = (t_v2d){1.0, 1.0}, .focus = 1.0};
}
