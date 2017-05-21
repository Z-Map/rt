/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkrendertree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:42:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/21 04:38:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tools.h"
#include "rt_tree.h"

static t_rtnode		*rendernodechilds(t_rtnode *childs, t_mattf m, t_mat3x2f *b)
{
	t_rtnode		*nchilds;
	t_rtnode		**c;

	if (!childs)
		return (NULL);
	c = &nchilds;
	while (c && childs)
	{
		if (!(*c = (t_rtnode *)rendernodedup(childs, m, b)))
			c = NULL;
		else
			c = &((*c)->next);
		childs = childs->next;
	}
	if (!c)
	{
		while (nchilds)
		{
			childs = nchilds->next;
			rmnode(&nchilds);
			nchilds = childs;
		}
	}
	return (nchilds);
}

t_rtrnode			*rendernodedup(t_rtnode *node, t_mattf m, t_mat3x2f *b)
{
	t_rtrnode		*rnode;
	t_mat3x2f		lb;

	if (!node)
		return (NULL);
	pmattf_multiply(&m, &(((t_rtobi *)(node->content))->transform));
	lb = bound_transform(((t_rtobi *)(node->content))->bounds, m);
	rnode = mkrendernode((t_rtobi *)(node->content), m, lb);
	if (node->childs && (!(rnode->node.childs = rendernodechilds(
		node->childs, m, &lb))))
		rmnode((t_rtnode **)&rnode);
	else
	{
		((t_rtrnode *)rnode)->bound = lb;
		*b = bound_union(lb, *b);
	}
	return (rnode);
}

t_rtree				*mkrendertree(t_rtree *tree)
{
	t_rtree			*ntree;
	t_mat3x2f		gb;

	if (!tree || !(ntree = mktree(0)))
		return (NULL);
	gb = no_bound();
	if (!(ntree->node.childs = rendernodechilds(tree->node.childs,
		mattf_identity(), &gb)))
		rmtree(&ntree);
	else
	{
		ntree->max_depth = tree->max_depth;
		ntree->node = tree->node;
	}
	return (ntree);
}
