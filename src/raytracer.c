/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/19 14:33:07 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		**node_prefix(t_rtnode *node)
{
	void		**tmp;
	
	tmp = &node;
	while (*tmp)
	{
		if (!node->child)
		{
			if (t_rtnode->t_rtobi->obj.type | SPHERE)
				tmp++ = calc_sphere;
			if (t_rtnode->t_rtobi->obj.type | CONE)
				tmp++ = calc_cone;
			if (t_rtnode->t_rtobi->obj.type | PLAN)
				tmp++ = calc_plan;
			if (t_rtnode->t_rtobi->obj.type | CYLINDER)
				tmp++ = calc_cylinder
		}
		if (!node->next)
			if (t_rtnode->t_rtobi->obj.type | SPHERE)
				tmp++ = calc_sphere;
			if (t_rtnode->t_rtobi->obj.type | CONE)
				tmp++ = calc_cone;
			if (t_rtnod0e->t_rtobi->obj.type | PLAN)
				tmp++ = calc_plan;
			if (t_rtnode->t_rtobi->obj.type | CYLINDER)
				tmp++ = calc_cylinder
		}
	}
}
// Pour le moment la fonction est en iteratif. Il faut je pense la passer en 
// recursive, cela s'adaptera mieux a la structure du nodetree.
// mon void** est un type par default, a creuser.

double		positive_smallest(double a, double b)
{
	if (a < 0)
	{
		if (b < 0)
			return (b);
		return (NIFINITY);
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

double		calc_cone(t_objet *cone, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	angle;

	angle = t_cone->open * (M_PI / 180);
	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y - ray->dir.z * ray->dir.z * tan(angle) * tan(angle);
	b = 2 * (ray->origin.x * ray->dir.x + ray->origin.y * ray->dir.y - ray.dir.x * 0/*t_cone->orgine.x*/ - ray->direction.y * 0/*t_cone->origin.y*/ + (ray->dir.z * (0/*t_cone->origin.z*/ - ray->origin.z)) * tan(angle) * tan(angle));
	c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y + 0/*t_cone->origin.x*/ * 0/*t_cone->origin.x*/ + 0/*t_cone->origin.y*/ * 0/*t_cone->origin.y*/ - 2 * (ray->origin.x * 0/*t_cone->origin.x*/ + ray->origin.y * 0/*t_cone->origin.y*/) - (ray->origin.z * ray->origin.z - 2 * (ray->origin.z * 0/*t_cone->origin.z*/) + 0/*t_cone->origin.z*/ * 0/*t_cone.origin.z*/) * tan(angle) * tan(angle);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		return (positive_smallest((-b + delta) / (2 * a), (-b - delta) / (2 * a)));
	}
	return (INFINITY);
}

double		calc_plane(t_objet *plane, t_ray *ray)
{
	double	n;
	double	d;
	double	ret;

	n = plane->normal.x * (0/*plane->origin.x*/ - ray->origin.x) + plane->normal.y * (0/*->plane->origin.y*/ - ray->origin.y) + plane.normal.z * (0/*plane->origin.z*/ - ray->origin.z);

	d = plane->normal.x * ray->dir.x + plane->normal.y * ray->dir.y + plane->normal.z * ray->dir.z;
	if ((ret = n / d) > 0)
		return (ret);
	return (INFINITY);
}

double		calc_cylinder(t_objet *cylinder, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	ret;

	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y;
	b = 2 * (ray->origin.x * ray->dir.x + ray->origin.y * ray->dir.y - ray->dir.x * 0/*t_cylinder->origin.x*/ - ray->dir.y * 0/*t_cylinder->origin.y*/);
	c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y + 0/*t_cylinder->origin.x*/ * 0/*t_cylinder.origin.x*/ + 0/*t_cylinder->origin.y*/ * 0/*t_cylinder->origin.y*/ - 1/*t_cylinder->radius*/ * 1/*t_cylinder->radius*/ - 2 * (ray->origin.x * 0/*t_cylinder->origin.x*/ + ray->origin.y * 0/*t_cylinder->origin.y*/);
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		ret = positive_smallest((-b + delta) / (2 * a), (-b - delta) / (2 * a));
		return (ret);
	}
	return (INFINITY);
}

static double	sphere_eq_delta(t_objet *sphere, t_ray *ray, double *a, double *b)
{
	t_vector	ray_dir;
	t_point		ray_origin;
	t_point		sphere_origin;
	double		radius;
	double		c;

	ray_dir = ray_dir;
	ray_origin = ray_origin;
	sphere_origin = 0/*sphere_origin*/;
	radius = 1 /*sphere->radius*/;
	*a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y + ray_dir.z * ray_dir.z;
	*b = 2 * (ray_dir.x * (ray_origin.x - 0/*sphere_origin.x*/) + ray_dir.y * (ray_dir.y - 0/*sphere_origin.y*/) + ray_dir.z * (ray_origin.z - 0/*sphere_origin*/));
	c = (ray_origin.x - 0/*sphere_origin.x*/) * (ray_origin.z - 0/*sphere_origin.x*/) + (ray_origin.y - 0/*sphere_origin.y*/) * (ray_origin.y - 0/*sphere_origin.y*/) + (ray_origin.z - 0/*sphere_origin.z*/) * (ray_origin.z - 0/*sphere_origin.z*/) - 1/*radius*/ * 1/*radius*/;
	return (c);
}

double			sphere_equation(t_objet *sphere, t_ray *ray)
{
	double	ret;
	double	a;
	double	b;
	double	c;
	double	delta;

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
