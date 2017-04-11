/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_addchild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:31:28 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/10 17:51:37 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_addchild(t_rtnode *parent, t_rtnode *node)
{
	if (!parent)
		return (NULL);
	node->next = parent->childs;
	parent->childs = node;
	node->parent = parent;
	return (node);
}
