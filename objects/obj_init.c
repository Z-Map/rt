/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 14:00:29 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/13 15:11:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaders.h"
#include "libft.h"

void			rt_obj_init_shader(t_obj *obj)
{
	if (!(obj->shader = init_shaders()))
	{
		ft_putendl_fd("error: failed to malloc shaders", 2);
		return ;
	}
	init_shader(obj->shader, &shader_ambiant, NULL, 0x000000,
		&blend_add);
	init_shader(obj->shader, &rt_light_pow, NULL, 0x000000,
		&blend_multiply);
	init_shader(obj->shader, &shader_shadow, NULL, 0x7f7f7f,
		&blend_overlay);
	init_shader(obj->shader, &rt_specular_pow, NULL, 0x000000,
		&blend_add);
}

t_obj			*rt_obj_init(t_obj *obj, int type)
{
	obj->id = 0;
	obj->cfgbits = 0;
	obj->type = (t_type)(type & ~NOSHADER);
	obj->next = NULL;
	obj->childs = NULL;
	obj->content = NULL;
	obj->trans = geo_mk4_identity();
	obj->bounds = (t_box){0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	obj->hitbox = (t_box){0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	obj->rotation = (t_v4d){0.0, 0.0, 0.0, 0.0};
	obj->inters = NULL;
	obj->normal = NULL;
	obj->parent = NULL;
	obj->refractive_index = 1.05;
	if (!(type & VISIBLE))
		type |= NOSHADER;
	if (!(type & NOSHADER))
		rt_obj_init_shader(obj);
	else
		obj->shader = NULL;
	return (obj);
}
