/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrtree_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/01 23:24:32 by qloubier         ###   ########.fr       */
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
	i = tree->visible_len;
	while (i-- > 1)
		ft_printf("(%s), ", tree->visible[i]->content->obj->name);
	ft_printf("(%s)\n", tree->visible[i]->content->obj->name);
	return (1);
}
