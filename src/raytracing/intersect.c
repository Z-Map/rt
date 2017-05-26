/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/20 13:23:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_prototype.h"
#include "rt_object.h"
#include "rt_tree.h"

//#include "rt_render.h"
/*
void			**node_prefix(t_rtnode *node)
{
	t_rtnode	**tmp;
	t_rtobi		*inst;

	tmp = &node;
	while (*tmp)
	{
		if (!(*tmp)->childs)
		{
			inst = (t_rtobi *)(*tmp)->content;
			if (inst->obj->type | SPHERE)
				tmp++ = calc_sphere();
			if (inst->obj->type | CONE)
				tmp++ = calc_cone();
			if (inst->obj->type | PLAN)
				tmp++ = calc_plan();
			if (inst->obj->type | CYLINDER)
				tmp++ = calc_cylinder();
		}
		if (!(*tmp)->next)
		{
			inst = (t_rtobi *)(*tmp)->content;
			if (inst->obj->type | SPHERE)
				tmp++ = calc_sphere();
			if (inst->obj->type | CONE)
				tmp++ = calc_cone();
			if (inst->obj->type | PLAN)
				tmp++ = calc_plan();
			if (inst->obj->type | CYLINDER)
				tmp++ = calc_cylinder();
		}
	}
}*/
// Pour le moment la fonction est en iteratif. Il faut je pense la passer en
// recursive, cela s'adaptera mieux a la structure du nodetree.
// mon void** est un type par default, a creuser.

double		positive_smallest(double a, double b)
{
	if (a < 0)
	{
		if (b < 0)
			return (b);
		return (INFINITY);
	}
	if (b < 0)
	{
		if (a > 0)
			return (a);
		return (INFINITY);
	}
	if (a < b)
		return (a);
	return (b);
}

double		calc_cone(t_rtobd *cone, t_rtray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	angle;

	(void)cone;
	angle = cone->cone.angle * (M_PI / 180);
	a = ray->direction.x * ray->direction.x + ray->direction.y * ray->direction.y - ray->direction.z * ray->direction.z * tan(angle) * tan(angle);
	b = 2 * (ray->start.x * ray->direction.x +
			ray->start.y * ray->direction.y -
			ray->direction.x * 0/*t_cone->orgine.x*/ -
			ray->direction.y * 0/*t_cone->origin.y*/ +
			(ray->direction.z * (0/*t_cone->origin.z*/ -
			ray->start.z)) * tan(angle) * tan(angle));
	c = ray->start.x * ray->start.x + ray->start.y * ray->start.y + 0/*t_cone->origin.x*/ * 0/*t_cone->origin.x*/ + 0/*t_cone->origin.y*/ * 0/*t_cone->origin.y*/ - 2 * (ray->start.x * 0/*t_cone->origin.x*/ + ray->start.y * 0/*t_cone->origin.y*/) - (ray->start.z * ray->start.z - 2 * (ray->start.z * 0/*t_cone->origin.z*/) + 0/*t_cone->origin.z*/ * 0/*t_cone.origin.z*/) * tan(angle) * tan(angle);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		return (positive_smallest((-b + delta) / (2 * a), (-b - delta) / (2 * a)));
	}
	return (INFINITY);
}

double		calc_plane(t_rtobd *plane, t_rtray *ray)
{
	double	n;
	double	d;
	double	ret;
	t_v3f	nor;

	nor = (t_v3f){0.0f, 0.0f, 1.0f};
	(void)plane;
	n = nor.x * (0/*plane->origin.x*/ - ray->start.x) + nor.y * (0/*->plane->origin.y*/ - ray->start.y) + nor.z * (0/*plane->origin.z*/ - ray->start.z);

	d = nor.x * ray->direction.x + nor.y * ray->direction.y + nor.z * ray->direction.z;
	if ((ret = n / d) > 0)
		return (ret);
	return (INFINITY);
}

double		calc_cylinder(t_rtobd *cylinder, t_rtray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	ret;

	(void)cylinder;
	a = ray->direction.x * ray->direction.x + ray->direction.y * ray->direction.y;
	b = 2 * (ray->start.x * ray->direction.x + ray->start.y * ray->direction.y - ray->direction.x * 0/*t_cylinder->origin.x*/ - ray->direction.y * 0/*t_cylinder->origin.y*/);
	c = ray->start.x * ray->start.x + ray->start.y * ray->start.y + 0/*t_cylinder->origin.x*/ * 0/*t_cylinder.origin.x*/ + 0/*t_cylinder->origin.y*/ * 0/*t_cylinder->origin.y*/ - 1/*t_cylinder->radius*/ * 1/*t_cylinder->radius*/ - 2 * (ray->start.x * 0/*t_cylinder->origin.x*/ + ray->start.y * 0/*t_cylinder->origin.y*/);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		ret = positive_smallest((-b + delta) / (2 * a), (-b - delta) / (2 * a));
		return (ret);
	}
	return (INFINITY);
}

static double	sphere_eq_delta(t_rtobd *sphere, t_rtray *ray, double *a, double *b)
{
	t_v3f		ray_dir;
	t_v3f		ray_origin;
	t_v3f		sphere_origin;
	double		radius;
	double		c;

	(void)sphere;
	ray_dir = ray->direction;
	ray_origin = ray->start;
	sphere_origin = (t_v3f){0, 0, 0}/*sphere_origin*/;
	radius = 1 /*sphere->radius*/;
	*a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y + ray_dir.z * ray_dir.z;
	*b = 2 * (ray_dir.x * (ray_origin.x - 0/*sphere_origin.x*/) + ray_dir.y * (ray_dir.y - 0/*sphere_origin.y*/) + ray_dir.z * (ray_origin.z - 0/*sphere_origin*/));
	c = (ray_origin.x - 0/*sphere_origin.x*/) * (ray_origin.z - 0/*sphere_origin.x*/) + (ray_origin.y - 0/*sphere_origin.y*/) * (ray_origin.y - 0/*sphere_origin.y*/) + (ray_origin.z - 0/*sphere_origin.z*/) * (ray_origin.z - 0/*sphere_origin.z*/) - 1/*radius*/ * 1/*radius*/;
	return (c);
}

double			calc_sphere(t_rtobd *sphere, t_rtray *ray)
{
	double	ret;
	double	a;
	double	b;
	double	c;
	double	delta;

	(void)sphere;
	c = sphere_eq_delta(sphere, ray, &a, &b);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		ret = positive_smallest((-b + delta) / (2 * a), (-b - delta) / (2 * a));
		return (ret);
	}
	return (INFINITY);
}
