/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:17:17 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/22 13:32:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

void			recursive(t_rtnode *node, t_rtree *tree, t_ui maxd)
{
	if (node)
		maxd++;
	while (node && tree->nodelen++)
	{
		recursive(node->childs, tree, maxd);
		node = node->next;
	}
	if (tree->max_depth < maxd)
		tree->max_depth = maxd;
}

void			tree_stats(t_rtree *tree)
{
	if (!tree)
		return ;
	tree->nodelen = 0;
	tree->max_depth = 0;
	recursive(tree->node.childs, tree, 0);
}
