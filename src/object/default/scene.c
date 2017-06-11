/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 22:46:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_scene(t_rtobd *object)
{
	object->scene.sky = NULL;
	object->scene.ambient_light = (t_rgba){0,0,0,0};
}
