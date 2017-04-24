/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 01:59:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_light(t_rtobj *object)
{
	object->data.light = (struct s_rtlight){
		.material = NULL, .radius = 1.0, .angle = 1.0, .intensity = 1.0};
}
