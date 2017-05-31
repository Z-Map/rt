/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:15:56 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/31 19:50:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int			node_isoftype(t_rtobi *inst, void *env)
{
	t_ui	flags;
	t_ui	type;

	flags = (t_ui)((t_ul)env >> 32);
	type = (t_ui)((t_ul)env & 0xFFFFFFFFul);
	if (inst && (inst->obj->type | type))
		return (1);
	return (0);
}

// int			get_visible(t_tree *tree, t_rntree *rntree, int (*f)(void *env))
// {
// 	/* J'arrive pas à coder omg */
// }
//
// int			get_light(t_tree *tree, t_rntree *rntree, int (*f)(void *env))
// {
//    /* J'arrive pas à coder omg² */
// }
//
// t_rmgrtree	*make_render_tree(t_rtree *tree)
// {
// 	t_rntree	*rntree;
// 	int			(*vis)(void *);
// 	int			(*lgt)(void *);
//
// 	if (!tree || !(rntree = (t_rntree *)malloc(sizeof(t_rntree))))
// 		return (NULL);
// 	vis = &rt_is_visible;
// 	lgt = &rt_is_light;
// 	get_visible(tree, rntree, vis);
// 	get_light(tree, rntree, lgt);
// 	if (!(rntree->ldepth) || !(rntree->vdepth))
// 	{
// 		if (rntree)
// 			free(rntree);
// 		return (NULL);
// 	}
// 	return (rntree);
// }
