/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunlight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:58:54 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 17:24:47 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_sunlight(t_rtobd *object)
{
	object->sunlight.material = NULL;
	object->sunlight.radius = 1.0;
	object->sunlight.intensity = 1.0;
}
