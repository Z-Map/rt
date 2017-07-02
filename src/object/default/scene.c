/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:32:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_scene(t_rtobd *object)
{
	object->scene.sky = NULL;
	object->scene.ambient_light = (t_rgba){0x11u, 0x11u, 0x11u, 0xFFu};
	object->scene.filter = (t_rgba){0x00u, 100u, 100u, 0x50u};
}
