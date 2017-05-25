/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkrendertree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:42:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:39:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tools.h"
#include "rt_object.h"
#include "rt_tree.h"

static t_rtnode		*find_cam(t_rtnode *n)
{
	t_rtnode		*c;

	if (!n)
		return (NULL);
	if (((t_rtobi *)n->content)->obj->type & CAMERA)
		return (n);
	if ((c = find_cam(n->childs)))
		return (c);
	else if ((c = find_cam(n->next)))
		return (c);
	return (NULL);
}

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
	lb = instance_getbound((t_rtobi *)(node->content), &m);
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
		ntree->node.flags |= TREET_RENDER;
		ntree->max_depth = tree->max_depth;
		ntree->nodelen = tree->nodelen;
		ntree->camera = find_cam(ntree->node.childs);
		print_tree(ntree);
	}
	return (ntree);
}
