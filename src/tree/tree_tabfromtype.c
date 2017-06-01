/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tabfromtype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:15:56 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/01 23:18:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int			node_isoftype(t_rtobi *inst, void *env)
{
	t_ui	flags;
	t_ui	type;

	flags = ((t_ui *)env)[0];
	type = ((t_ui *)env)[1];
	if (inst && (inst->obj->type | type))
	{
		if (flags & RT_LEN)
			((t_ui *)env)[2] += 1;
		return ((flags & RT_GET) ? 1 : 0);
	}
	return (0);
}

t_rtnode		**node_tabfromtype(t_rtree *tree, t_rtobt type, size_t *len)
{
	t_ui		arg[3];
	t_rtnode	**tab;
	t_rtnode	*tmp;

	arg[0] = RT_LEN;
	arg[1] = (t_ui)type;
	arg[2] = 0;
	tree_find((t_rtnode *)tree, (int (*)(void *, void *))&node_isoftype, arg);
	*len = arg[2];
	if (!arg[2])
		return (NULL);
	tab = (t_rtnode **)malloc(arg[2] * sizeof(t_rtnode *));
	tmp = (t_rtnode *)tree;
	arg[0] = RT_GET;
	while (arg[2]--)
	{
		if (tmp)
			tmp = tree_find(tmp, (int (*)(void *, void *))&node_isoftype, arg);
		tab[arg[2]] = tmp;
	}
	return (tab);
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
