/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrtree_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 13:18:16 by qloubier         ###   ########.fr       */
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
	if (tree->lights)
	{
		i = tree->lights_len;
		while (i-- > 1)
		{
			if (tree->lights[i])
				ft_printf("(%s), ", tree->lights[i]->content->obj->name);
			else
				ft_printf("!ERROR!, ");
		}
		if (tree->lights[i])
			ft_printf("(%s)\n", tree->lights[i]->content->obj->name);
		else
			ft_printf("!ERROR!, ");
	}
	return (1);
}
