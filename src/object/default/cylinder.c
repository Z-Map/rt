/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:00:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_cylinder(t_rtobj *object)
{
	object->data.cylinder = (struct s_rtcylinder){
		.material = NULL, .radius = 1};
}
