/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:50:09 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/01 23:15:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode			*find_node(t_rtnode *node, void *content)
{
	t_rtnode		*tmp;

	if (!node || !content)
		return (NULL);
	while (node)
	{
		if (node->content == content)
			return (node);
		else if ((tmp = find_node(node->childs, content)))
			return (tmp);
		node = node->next;
	}
	return (NULL);
}

t_rtnode			*tree_chr(t_rtree *tree, void *content)
{
	return (find_node(tree->node.childs, content));
}
