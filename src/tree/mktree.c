/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mktree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:20:09 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/15 22:49:51 by qloubier         ###   ########.fr       */
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
	tree->node.parent = (t_rtnode *)tree;
	tree->node.next = NULL;
	tree->node.content = NULL;
	if (num == 0)
		tree->node.childs = NULL;
	else
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
