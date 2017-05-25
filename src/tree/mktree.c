/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mktree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:20:09 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/25 21:38:08 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

t_rtree			*mktree(size_t num, ...)
{
	t_rtree		*tree;
	t_rtnode	*tmp;
	va_list		nodes;

	if (!(tree = (t_rtree *)malloc(sizeof(t_rtree))))
		return (NULL);
	tree->buffer = NULL;
	tree->node = (t_rtnode){.parent = (t_rtnode *)tree, .next = NULL,
		.childs = NULL, .content = NULL, .flags = 0, .type = TREET_TREE};
	if (num)
	{
		va_start(nodes, num);
		tree->node.childs = va_arg(nodes, t_rtnode *);
		while (--num > 0)
		{
			tmp = va_arg(nodes, t_rtnode *);
			tmp->next = tree->node.childs;
			tree->node.childs = tmp;
		}
		va_end(nodes);
	}
	return (tree);
}
