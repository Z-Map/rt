/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 22:36:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"
#include "rt_object.h"

void			object_default_mesh(t_rtobd *object)
{
	object->mesh.material = NULL;
	object->mesh.vertex_len = 0;
	object->mesh.poly_len = 0;
	object->mesh.vertex = NULL;
	object->mesh.normale = NULL;
	object->mesh.uv = NULL;
	object->mesh.poly = NULL;
}
