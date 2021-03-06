/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunlight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:58:54 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 19:21:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_sunlight(t_rtobd *object)
{
	object->sunlight.color = (t_rgba){255, 255, 255, 255};
	object->sunlight.radius = 0.0;
	object->sunlight.intensity = 1.0;
}
