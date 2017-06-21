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

t_rtnode			*init_ui(t_v2i dim)
{
	t_rtnode		*tmp;
	t_rtnode		*node;
	t_layer_root	*root;

	//CREATION DU PREMIER ELEMENT
	if (!(root = mklayer_root(dim)))
		return (0);
	node = mknode((t_rtobi *)(root));
	node->type = TE_ROOT;
	node->flags = get_id_ui_node();
	// ajout de l enfant au noeud parent
	node->parent = node;

	//ELEMENT SUR LA GAUVHR
	if (!(tmp = tree_addchild(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.2, 1.0},\
	(t_v4i){200, 100, 100, 200}, PL_LEFT))))
		return (0);
        if (!(tree_addchild_wid(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.2, 0.8},\
          (t_v4i){0, 0, 255, 200}, PL_MIDDLE), 1)))
         	return (0);
	//tets d ajout de bordure sur l image principal id : 3
        if (!(tree_addchild_wid(node, mknlayer_border((t_v2f){0.0, 0.0}, (t_v2f){1.0, 1.0},\
 	      (t_v4i){0, 255, 0, 200}, PL_MIDDLE), 1)))
		return (0);

	/*
	** modif of property of border : 3
	*/
	tmp = tree_found_node_with_id(node, 3);
	((t_layer_border *)(tmp->content))->valid_border = 4;

	//creation de l element de droit 4 - 6
	if (!(tmp = tree_addchild(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.2, 1.0},\
	(t_v4i){200, 100, 100, 200}, PL_RIGHT))))
		return (0);
	if (!(tree_addchild_wid(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.2, 0.8},\
	(t_v4i){0, 0, 255, 200}, PL_MIDDLE), 4)))
		return (0);
	//tets d ajout de bordure sur l image principal id : 3
	if (!(tree_addchild_wid(node, mknlayer_border((t_v2f){0.0, 0.0}, (t_v2f){1.0, 1.0},\
	(t_v4i){0, 255, 0, 200}, PL_MIDDLE), 4)))
		return (0);
	tmp = tree_found_node_with_id(node, 6);
	((t_layer_border *)(tmp->content))->valid_border = 2;
	/*
	** create de l element du haut : 7 - 9
	*/
	if (!(tmp = tree_addchild(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.36, 0.25},\
	(t_v4i){200, 100, 100, 200}, PL_TOP))))
		return (0);
	if (!(tree_addchild_wid(node, mknlayer_border((t_v2f){0.0, 0.0}, (t_v2f){1.0, 1.0},\
	(t_v4i){0, 255, 0, 200}, PL_MIDDLE), 7)))
		return (0);
	if (!(tree_addchild_wid(node, mknlayer_rect((t_v2f){0.0, 0.0}, (t_v2f){0.8, 0.8},\
	(t_v4i){0, 0, 255, 200}, PL_MIDDLE), 7)))
		return (0);
	tmp = tree_found_node_with_id(node, 8);
	((t_layer_border *)(tmp->content))->valid_border = 14;
	return (node);
}
