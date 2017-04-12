/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_setparent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:16:10 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/12 16:22:12 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_setparent(t_rtnode *node, t_rtnode *parent)
{
	if (!parent || !node)
		return (NULL);
	if (node->parent)
		tree_delchild(node->parent, node);
	node->parent = parent;
	node->next = parent->childs;
	parent->childs = node;
	return (node);
}
