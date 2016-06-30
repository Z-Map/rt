/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo_setup_cyl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <dboudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:19:24 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/30 12:13:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "libft.h"

int					yolo_setup_cyl(t_obj *obj, size_t ac, char **av)
{
	if (ac < CYL_TEXTURE)
	{
		ft_putstr("error: failed to setup object type Cylinder\n");
		return (1);
	}
	ft_strtoupper(av[CYL_COLOR_POS]);
	((t_cyl*)obj->content)->radius = (float)ft_atod(av[PROP_SIZE]);
	((t_cyl*)obj->content)->color = yolo_setup_color(av[CYL_COLOR_POS]);
	if (av[CYL_TEXTURE] != NULL)
		yolo_setup_texture(obj, av, CYL_TEXTURE);
	rt_obj_rotate(obj,
		(t_v4d){deg2rad(ft_atod(av[CYL_OR_X])),
		deg2rad(ft_atod(av[CYL_OR_Y])),
		deg2rad(ft_atod(av[CYL_OR_Z])),
		1.0});
	return (0);
}
