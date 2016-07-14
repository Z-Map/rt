/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 20:27:31 by alhote            #+#    #+#             */
/*   Updated: 2016/07/14 15:57:29 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "rt.h"
#include "shaders.h"

void			shader_reflection(t_shader *s, t_render *r, t_obj *light)
{
	t_ray		ray;

	ray = *r->ray;
	(void)light;
	ray.start = geo_addv4(r->intersection, geo_multv4(ray.dir,
		geo_dtov4d(-0.00001)));
	ray.dir = (t_v4d){
		r->ray->dir.x - 2.0 * geo_dotv4(r->ray->dir, r->normal) * r->normal.x,
		r->ray->dir.y - 2.0 * geo_dotv4(r->ray->dir, r->normal) * r->normal.y,
		r->ray->dir.z - 2.0 * geo_dotv4(r->ray->dir, r->normal) * r->normal.z,
		0.0
	};
	if (A(s->color_render) == 0xFF && ray.count < 2)
	{
		ray.count++;
		s->color_render = 0x000000;
		s->color_render = blend_add(rt_render(r->rt, &ray), s->color_render);
	}
}
