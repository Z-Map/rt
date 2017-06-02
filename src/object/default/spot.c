/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:29 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 12:55:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_spot(t_rtobd *object)
{
	object->spot.angle = 1.0;
	object->spot.radius = 1.0;
	object->spot.intensity = 1.0;
}
