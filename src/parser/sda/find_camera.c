/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:30:06 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/06 23:37:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_prototype.h"
#include "rt_object.h"
#include "rt_tree.h"
#include "rt_parser.h"

static int		is_camera(void *nd, void *env)
{
	t_rtobi		*inst;

	inst = (t_rtobi *)nd;
	(void)env;
	if (inst && (inst->obj) && (inst->obj->type == CAMERA))
		return (1);
	else
		return (0);
}

int				find_camera(t_rtree *tree)
{
	t_rtnode	*cam;

	if (!tree)
		return (-1);
	cam = tree_find(&(tree->node), &is_camera, NULL);
	if (!cam && !sda_make_node_parser((t_rtnode *)tree, CAMERA, "camera"))
		return (0);
	else if (!cam)
		cam = tree->node.childs;
	tree->camera = cam;
	return (1);
}
