/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:14 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 16:33:20 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_camera(t_rtobd *object)
{
	object->camera.fov = (t_v2f){1.0, 1.0};
	object->camera.focus = 1.0;
}
