/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/16 14:04:55 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RT.h>

void		calc_ray(t_env *env, double x, double y)
{
	t_ray *ray;
	t_cam *cam;

	ray = &env->ray;
	cam = &env->cam;
	cpy_tp3d(&env->ray.dir, sum_tp3d(env->viewplane.upleft, sub_t3d(
		mult_nb_tp3d(env->viewplane.rvec, x * env->xindent),
		mult_nb_tp3d(env->viewplane.upvec, y * env->yindent))));
	normalized(&env->ray.dir);
}

void		set_light(t_ray *light)
{
	set_tp3d(&light->pos, 0, 0, 300);
	set_tp3d(&light->dir, 0, 0, 0);
	light->next = NULL;
}

void		set_ray(t_ray *ray, t_env *env)
{
	ray->pos.x = env->cam.pos.x;
	ray->pos.y = env->cam.pos.y;
	ray->pos.z = env->cam.pos.z;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 0;
	ray->next = NULL;
}
