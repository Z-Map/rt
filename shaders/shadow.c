/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:13:19 by hantlowt          #+#    #+#             */
/*   Updated: 2016/07/13 21:33:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "rt.h"
#include "shaders.h"

void			shader_shadow(t_shader *s, t_render *r, t_obj *light)
{
	t_ray		ray;
	t_render	sw;

	ray = *r->ray;
	ray.start = geo_addv4(r->intersection, geo_multv4(ray.dir,
		geo_dtov4d(-0.00001)));
	ray.dir = geo_subv4(light->trans.w, r->intersection);
	ray.lenght = (double)INFINITY;
	sw = (t_render){
			&ray, r->rt,
			NULL,
			HUGE_VAL,
			0.0,
			(t_v4d){0.0, 0.0, 0.0, 0.0},
			ray.dir,
		};
	rt_node_foreach(sw.rt->tree.bounded, INFIX, &rt_render_foreach, &sw);
	rt_node_foreach(sw.rt->tree.unbounded, INFIX, &rt_render_foreach, &sw);
	if (sw.obj_intersect && geo_distv4(light->trans.w, r->intersection)
	> geo_distv4(sw.obj_intersect->trans.w, r->intersection))
	{
		s->color_render = blend_sub(s->color_render, 0x111111);
		shaders_disable_nexts(s);
	}
}