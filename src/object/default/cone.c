/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/08 16:33:58 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_cone(t_rtobd *object)
{
	object->cone.material = NULL;
	object->cone.angle = 1.0;
}
