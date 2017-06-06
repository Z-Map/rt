/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrtree_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/03 05:49:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"


int				rtree_update(t_rdrtree *tree)
{
	size_t		i;

	tree->visible = node_tabfromtype((t_rtree *)tree, VISIBLE,
		&(tree->visible_len));
	tree->lights = node_tabfromtype((t_rtree *)tree, LIGHT,
		&(tree->lights_len));
	// tree->negative = node_tabfromtype(tree, VISIBLE, &(tree->negative_len));
	if (tree->visible)
	{
		i = tree->visible_len;
		while (i-- > 1)
		{
			if (tree->visible[i])
				ft_printf("(%s), ", tree->visible[i]->content->obj->name);
			else
				ft_printf("!ERROR!, ");
		}
		if (tree->visible[i])
			ft_printf("(%s)\n", tree->visible[i]->content->obj->name);
		else
			ft_printf("!ERROR!, ");
	}
	return (1);
}
