/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/24 16:53:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_mesh(t_rtobj *object)
{
	object->data.mesh = (struct s_rtmesh){
		.material = NULL, .vertex_len = 0, .poly_len = 0,
		.vertex = NULL, .normale = NULL, .uv = NULL, .poly = NULL};
}
