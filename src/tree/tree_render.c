/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:42:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/20 20:58:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

static t_rtnode		*rendernodedup(t_rtnode *node, t_mattf m, t_mat3x2f *b)
{
	t_rtnode		*newnode;
	t_rtnode		*c;
	t_mat3x2f		lb;

	if (!node)
		return (NULL);
	pmattf_multiply(&m, &(((t_rtobi *)(node->content))->transform));
	lb = ((t_rtobi *)(node->content))->bounds;
	newnode = rendernodedup(node->childs, m, &lb);
	c = newnode;
	while (c && (c = c->next))
		c = rendernodedup(c, m, &lb);
	newnode = (t_rtnode *)mkrendernode((t_rtobi *)(node->content), m, newnode);
	newnode->next = node->next;
	(void)b;
	return (newnode);
}

t_rtrnode			*mkrendernode(t_rtobi *inst, t_mattf mtrx, t_rtnode *c)
{
	t_rtrnode		*node;

	if (!(node = (t_rtrnode *)malloc(sizeof(t_rtrnode))))
		return (NULL);
	node->node.parent = NULL;
	node->node.next = NULL;
	node->node.childs = c;
	node->node.flags = 0;
	node->node.type = TREET_NODE;
	node->node.content = (void *)inst;
	node->transform = mtrx;
	node->invert_transform = mattf_invert(&mtrx);
	node->bound = inst->bounds;
	return (node);
}

t_rtree				*mkrendertree(t_rtree *tree)
{
	t_rtnode		*node;
	t_mat3x2f		gb;

	node = rendernodedup(tree->node.childs, mattf_identity(), &gb);
	return (NULL);
}
