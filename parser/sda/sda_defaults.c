/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_defaults.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 21:24:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/30 01:57:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "sda.h"
#include "libft.h"
#include "unistd.h"
#include "parser.h"

static void	sda_set_lights_default(t_obj *obj)
{
	if (!(obj->cfgbits & SDB_COLOR))
		((t_cube*)obj->content)->color = 0xffffff;
	if (!(obj->cfgbits & SDB_INTEN))
		((t_plight*)obj->content)->intensity = 100.0;
	if (!(obj->cfgbits & SDB_SIZE))
		((t_plight*)obj->content)->radius = 100.0;
}

static void sda_set_camera_default(t_obj *obj)
{
	t_camera	*cam;

	cam = obj->content;
	if (!(obj->cfgbits & SDB_FOV))
		cam->fov = -49.124;
	yolo_camera_save(obj);
}

static int 	sda_set_obj_defaults(t_obj *obj, int mode, void *userdata)
{
	(void)mode;
	(void)userdata;
	if (obj->type == CAMERA)
		sda_set_camera_default(obj);
	else if (obj->type & LIGHTTYPE)
		sda_set_lights_default(obj);
	return (OK);
}

void		sda_set_defaults(t_obj *root)
{
	rt_node_foreach(root, PREFIX, &sda_set_obj_defaults, NULL);
}
