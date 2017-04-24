/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:01:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/24 16:10:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_scene(t_rtobj *object)
{
	object->data.scene = (struct s_rtscene){
		.ambient_light = NULL, .skybox = NULL};
}
