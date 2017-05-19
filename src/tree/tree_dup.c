/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:44:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/19 19:54:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode			*tree_nodedup(t_rtnode *node)
{
	t_rtnode		*newnode;

	if (!node || !(newnode = mknode((t_rtobi *)node->content)))
		return (NULL);
	newnode->flags = node->flags;
	newnode->type = node->type;
	newnode->childs = tree_nodedup(node->childs);
	if (node->childs && !newnode->childs)
		rmnode(&newnode);
	if (newnode && !(newnode->next = tree_nodedup(node->next)) && node->next)
		rmnode(&newnode);
	return (newnode);
}

t_rtree				*tree_dup(t_rtree *tree)
{
	t_rtree			*ntree;

	if (!tree || !(ntree = mktree(0)))
		return (NULL);
	return (ntree);
}
