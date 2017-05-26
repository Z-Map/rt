/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:44:43 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/20 19:53:33 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode			*tree_childup(t_rtnode *childs)
{
	t_rtnode		*newnode;

	if (!childs || !(newnode = mknode(childs->content)))
		return (NULL);
	newnode->flags = childs->flags;
	newnode->type = childs->type;
	newnode->childs = tree_childup(childs->childs);
	if (childs->childs && !newnode->childs)
		rmnode(&newnode);
	if (newnode && !(newnode->next = tree_childup(childs->next))
		&& childs->next)
		rmnode(&newnode);
	return (newnode);
}

t_rtnode			*tree_nodedup(t_rtnode *node)
{
	t_rtnode		*newnode;

	if (!node || !(newnode = mknode((t_rtobi *)node->content)))
		return (NULL);
	newnode->flags = node->flags;
	newnode->type = node->type;
	newnode->childs = tree_childup(node->childs);
	if (node->childs && !newnode->childs)
		rmnode(&newnode);
	return (newnode);
}

t_rtree				*tree_dup(t_rtree *tree)
{
	t_rtree			*ntree;

	if (!tree || !(ntree = mktree(0)))
		return (NULL);
	if (!(ntree->node.childs = tree_nodedup(tree->node.childs)))
	{
		rmtree(&tree);
		return (tree);
	}
	ntree->max_depth = ntree->max_depth;
	ntree->nodelen = ntree->nodelen;
	return (ntree);
}
