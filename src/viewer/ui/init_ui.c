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

	if (!(root = mklayer_root(dim)))
		return (0);
	node = mknode((t_rtobi *)(root));
	node->type = TE_ROOT;
	node->flags = get_id_ui_node();
	// ajout de l enfant au noeud parent
	node->parent = node;
	if (!(tmp = tree_addchild(node, mknlayer_rect((t_v2f){0.4,0.4}, (t_v2f){0.2, 0.2},\
	(t_v4i){200,100,100,255}, 0))))
		return (0);
        if (!(tree_addchild_wid(node, mknlayer_rect((t_v2f){0.1,0.1}, (t_v2f){0.8, 0.8},\
        (t_v4i){0,0,255,255}, 0), 1)))
          	return (0);
	//node->childs->parent = node;
	tmp = tree_found_node_with_id(node, 2);
	printf("tmp->flags : %d | %d\n", tmp->flags, tmp->type);
	return (node);
}
