/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mktree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:20:09 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/20 16:52:15 by lcarreel         ###   ########.fr       */
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
	if (num == 0)
		tree = NULL;
	va_start(nodes, num);
	tree->node.parent = NULL;
	tree->node.next = NULL;
	tree->node.childs = va_arg(nodes, t_rtnode *);
	while (--num > 0)
	{
		tmp = va_arg(nodes, t_rtnode *);
		tmp->next = tree->node.childs;
		tree->node.childs = tmp;
	}
	va_end(nodes);
	return (tree);
}
