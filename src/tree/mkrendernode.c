/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkrendernode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 02:45:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:38:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tools.h"
#include "rt_tree.h"

t_rtrnode			*mkrendernode(t_rtobi *inst, t_mattf mtrx, t_mat3x2f lb)
{
	t_rtrnode		*node;

	if (!(node = (t_rtrnode *)malloc(sizeof(t_rtrnode))))
		return (NULL);
	node->node.parent = NULL;
	node->node.next = NULL;
	node->node.childs = NULL;
	node->node.flags = 0;
	node->node.type = TREET_NODE | TREET_RENDER;
	node->node.content = (void *)inst;
	node->transform = mtrx;
	node->invert_transform = mattf_invert(&mtrx);
	node->lbound = lb;
	return (node);
}
