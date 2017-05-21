/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:17:17 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/21 18:07:39 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

void			recursive(t_rtnode *node, t_rtree *tree, int maxd)
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
	t_rtnode	*tmp;
	int			maxd;

	if (!tree)
		return ;
	tree->nodelen = 0;
	tree->max_depth = 0;
	maxd = 0;
	tmp = tree->node.childs;
	recursive(tmp, tree, maxd);
}
