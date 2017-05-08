/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 17:20:36 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_sphere(t_rtobd *object)
{
	object->sphere.material = NULL;
	object->sphere.radius = 1.0;
}
