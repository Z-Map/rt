/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raytracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:05:04 by fanno             #+#    #+#             */
/*   Updated: 2017/05/16 14:29:20 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

t_p3d		cpy_tp3d(t_p3d *dest, t_p3d src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_p3d		sum_tp3d(t_p3d vector1, t_p3d vector2)
{
	t_p3d		result;

	result.x = vector1.x + vector2.x;
	result.y = vector1.y + vector2.y;
	result.z = vector1.z + vector2.z;
	return (result);
}

t_p3d		sub_tp3d(t_p3d vector1, t_p3d vector2)
{
	t_p3d		result;

	result.x = vector1.x - vector2.x;
	result.y = vector1.y - vector2.y;
	result.z = vector1.z - vector2.z;
	return (result);
}

t_p3d		mult_nb_tp3d(t_p3d vector, double nb)
{
	t_p3d		restult;

	result.x = vector1.x * vector2.x;
	result.y = vector1.y * vector2.y;
	result.z = vector1.z * vector2.z;
	return (result);
}

void		normalized(t_p3d *point)
{
	double		norm;

	norm = sqrt(point->x * point->x + point.y * point.y +
			point->z * point->z);
	point->x = point->x / norm;
	point->y = point->y / norm;
	point->z = point->z / norm;
}
}
