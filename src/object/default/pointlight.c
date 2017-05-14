/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 17:24:56 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_pointlight(t_rtobd *object)
{
	object->pointlight.material = NULL;
	object->pointlight.radius = 1.0;
	object->pointlight.intensity = 1.0;
}
