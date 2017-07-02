/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tabfromtype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 01:00:01 by lcarreel          #+#    #+#             */
/*   Updated: 2017/07/03 01:00:16 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

int				node_isoftype(t_rtobi *inst, void *env)
{
	t_ui		flags;
	t_ui		type;

	flags = ((t_ui *)env)[0];
	type = ((t_ui *)env)[1];
	if (inst && (inst->obj->type & type))
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
