/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 19:21:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_pointlight(t_rtobd *object)
{
	object->pointlight.color = (t_rgba){255, 255, 255, 255};
	object->pointlight.radius = 20.0;
	object->pointlight.intensity = 1.0;
}
