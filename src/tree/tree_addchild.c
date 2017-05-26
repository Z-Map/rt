/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_addchild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:31:28 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/15 22:42:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_addchild(t_rtnode *parent, t_rtnode *node)
{
	if (!parent || !node)
		return (NULL);
	node->next = parent->childs;
	parent->childs = node;
	node->parent = parent;
	return (node);
}
