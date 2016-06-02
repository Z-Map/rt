/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 20:51:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/03 00:16:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"
#include <math.h>
#define PROP_SIZE 0
#define S_COLOR_POS 4
#define CAMERA_OR_X 3
#define CAMERA_OR_Y 4
#define CAMERA_OR_Z 5

static unsigned int	yolo_setup_color(const char *strcolor)
{
	char			**split;
	unsigned int	color;
	size_t			splitsize;

	if (ft_strcount(strcolor, ':') != 2)
		return (COLOR_BLACK);
	if (!(split = ft_strsplit(strcolor, ':')))
		return (COLOR_BLACK);
	splitsize = ft_tabcount((void**)split);
	color = (splitsize == 4) ? (unsigned int)((((ft_atoi(split[0]) & 0xff) << \
		16) | (ft_atoi(split[1]) & 0xff) << 8) | (ft_atoi(split[2]) & 0xff)) : \
		COLOR_BLACK;
	ft_free_tab(split, splitsize);
	free(split);
	return (color);
}

static int			yolo_setup_camera(t_obj *obj, size_t ac, char **av)
{
	if (ac < CAMERA_OR_Z)
	{
		ft_printf("error: failed to setup camera\n");
		return (1);
	}
	((t_camera*)obj->content)->fov = (float)(49.124 / 180.0 * M_PI_2);
	obj->trans = draw_matrix_multiply_axes_m4(
		(t_v4d){ft_atod(av[CAMERA_OR_X]) / 180.0 * M_PI_2,
			ft_atod(av[CAMERA_OR_Y]) / 180.0 * M_PI_2,
			ft_atod(av[CAMERA_OR_Z]) / 180.0 * M_PI_2, 1.0},
		(t_v4d){1.0, 1.0, 1.0, 1.0}, obj->trans.w);
	draw_putm4(obj->trans, 6);
	ft_putchar('\n');
	t_m4	pute = draw_make_matrix_m4_y(
		(t_v4d){1.0, 1.0, 1.0, 1.0},
		1.0,
		(t_v4d){1.0, 1.0, 1.0, 1.0});
	obj->trans = draw_matrix_multiply_matrix_m4(obj->trans, &pute);
	draw_putm4(obj->trans, 6);
	ft_putchar('\n');
	exit(0);
	//return (0);
}

int					yolo_setup(t_obj *obj, size_t ac, char **av)
{
	if (!ac)
		return (1);
	if (obj->type & (SPHERE | CUBE))
	{
		if (ac < 4)
			return (1);
		((t_sphere*)obj->content)->radius = (float)ft_atod(av[PROP_SIZE]);
		((t_sphere*)obj->content)->color = yolo_setup_color(av[S_COLOR_POS]);
	}
	else if (obj->type == CAMERA)
		return (yolo_setup_camera(obj, ac, av));
	return (0);
}
