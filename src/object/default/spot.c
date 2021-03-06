/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:29 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 19:21:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_spot(t_rtobd *object)
{
	object->spot.color = (t_rgba){255, 255, 255, 255};
	object->spot.angle = 45.0;
	object->spot.radius = 30.0;
	object->spot.intensity = 1.0;
}
