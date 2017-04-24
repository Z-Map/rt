/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:00:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:00:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_sphere(t_rtobj *object)
{
	object->data.sphere = (struct s_rtsphere){
		.material = NULL, .radius = 1.0};
}
