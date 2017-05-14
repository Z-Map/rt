/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 17:19:36 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_scene(t_rtobd *object)
{
	object->scene.ambient_light = NULL;
	object->scene.skybox = NULL;
}
