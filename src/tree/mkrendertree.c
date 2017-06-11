/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkrendertree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:42:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 20:52:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tools.h"
#include "rt_object.h"
#include "rt_tree.h"

// static t_rtnode		*find_cam(t_rtnode *n)
// {
// 	t_rtnode		*c;
//
// 	if (!n)
// 		return (NULL);
// 	if (((t_rtobi *)n->content)->obj->type & CAMERA)
// 		return (n);
// 	if ((c = find_cam(n->childs)))
// 		return (c);
// 	else if ((c = find_cam(n->next)))
// 		return (c);
// 	return (NULL);
// }

// static t_rtnode	*rendernodechilds(t_rtnode *childs, t_mattf m, t_mat3x2f *b)
// {
// 	t_rtnode		*nchilds;
// 	t_rtnode		**c;
//
// 	if (!childs)
// 		return (NULL);
// 	c = &nchilds;
// 	while (c && childs)
// 	{
// 		if (!(*c = (t_rtnode *)rendernodedup(childs, m, b)))
// 			c = NULL;
// 		else
// 			c = &((*c)->next);
// 		childs = childs->next;
// 	}
// 	if (!c)
// 	{
// 		while (nchilds)
// 		{
// 			childs = nchilds->next;
// 			rmnode(&nchilds);
// 			nchilds = childs;
// 		}
// 	}
// 	return (nchilds);
// }
//
// t_rtrnode		*rendernodedup(t_rtnode *node, t_mattf m, t_mat3x2f *b)
// {
// 	t_rtrnode	*rnode;
// 	t_mat3x2f	lb;
//
// 	if (!node)
// 		return (NULL);
// 	pmattf_multiply(&m, &(((t_rtobi *)(node->content))->transform));
// 	lb = instance_getbound((t_rtobi *)(node->content), &m);
// 	rnode = mkrendernode((t_rtobi *)(node->content), m, lb);
// 	if (node->childs && (!(rnode->node.childs = rendernodechilds(
// 		node->childs, m, &lb))))
// 		rmnode((t_rtnode **)&rnode);
// 	else
// 	{
// 		((t_rtrnode *)rnode)->bound = lb;
// 		*b = bound_union(lb, *b);
// 	}
// 	return (rnode);
// }

static void		*clean(t_rtnode *node)
{
	t_rtnode	*n;
	t_rtnode	*c;

	if (!node)
		return (NULL);
	n = node->childs;
	while (n)
	{
		c = n->next;
		clean(n);
		n = c;
	}
	free (node);
	return (NULL);
}

static t_rtnode	*rdrdn(t_rtnode *p, t_rtnode *node, t_mattf m, t_mat3x2f *b)
{
	t_rtrnode	*rnode;
	t_rtnode	**rnc;
	t_rtnode	*n;
	t_mat3x2f	lb;

	pmattf_multiply(&m, &(((t_rtobi *)(node->content))->transform));
	lb = instance_getbound((t_rtobi *)(node->content), &m);
	if (!(rnode = mkrendernode((t_rtobi *)(node->content), m, lb)))
		return (NULL);
	rnode->node.parent = p;
	n = node->childs;
	rnc = &(rnode->node.childs);
	while (n)
	{
		if (!(*rnc = rdrdn((t_rtnode *)rnode, n, m, &lb)))
			return (clean((t_rtnode *)rnode));
		n = n->next;
		rnc = &((*rnc)->next);
	}
	rnode->bound = lb;
	*b = bound_union(lb, *b);
	return ((t_rtnode *)rnode);
}

static int		startloop(t_rtree *tree, t_rtnode *ntree)
{
	t_rtnode	*n;
	t_rtnode	**nc;
	t_mat3x2f	gb;

	gb = no_bound();
	n = tree->node.childs;
	nc = &(ntree->childs);
	while (n && (*nc = rdrdn(ntree, n, mattf_identity(), &gb))
		&& (n = n->next))
		nc = &((*nc)->next);
	if (!n)
		return (1);
	clean(ntree->childs);
	return (0);
}

t_rdrtree		*mkrendertree(t_rtree *tree)
{
	t_rtree		*ntree;

	if (!tree || !(ntree = (t_rtree *)malloc(sizeof(t_rdrtree))))
		return (NULL);
	*(t_rdrtree *)ntree = (t_rdrtree){ .tree = (t_rtree){ .node = (t_rtnode){
		.parent = (t_rtnode *)ntree, .next = NULL, .childs = NULL,
		.content = NULL, .flags = TREET_RENDER,
		.type = TREET_TREE | TREET_RENDER},
		.max_depth = tree->max_depth, .nodelen = tree->nodelen, .buffer = NULL,
		.camera = NULL, .scene = tree->scene},
		.visible = NULL, .negative = NULL, .lights = NULL};
	if (!startloop(tree, (t_rtnode *)ntree))
		free(&ntree);
	else
	{
		ntree->camera = tree_chr(ntree, tree->camera->content);
		rtree_update((t_rdrtree *)ntree);
	}
	return ((t_rdrtree *)ntree);
}
