/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:41:46 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 20:01:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>
#include <stdio.h>

t_rtnode				*init_ui(t_rt *rt, t_v2i dim)
{
	t_rtnode			*node;
	t_layer_root		*root;
	t_v4i				color[2];

	color[0] = (t_v4i){255, 0, 255, 100};
	color[1] = (t_v4i){255, 255, 0, 100};
	if (!(root = mklayer_root(dim)))
		return (0);
	node = mknode((t_rtobi *)(root));
	node->type = TE_ROOT;
	node->flags = get_id_ui_node();
	node->parent = node;
	if (!(rt->viewer.layer_main_loadbar = tree_addchild(node,\
	mknlayer_loadbar((t_v2f){0.0, 0.0}, (t_v2f){1.0, 0.15666},\
color, PL_BOTTOM))))
		return (0);
	return (node);
}
