/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:50:09 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/21 16:47:18 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"


t_rtnode			*find_node(t_rtnode *node, void *content)
{
	t_rtnode		*tmp;

	if (!node || !content)
		return (NULL);
	else
	{
		while (node)
		{
			if (tmp->content == content)
				return (tmp);
			if ((tmp = find_node(node->childs, content)))
				return (tmp);
			node = node->next;
		}
	}
	return (NULL);
}

t_rtnode			*tree_chr(t_rtree *tree, void *content)
{
	return (find_node(&(tree->node), content));
}
