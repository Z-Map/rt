/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_collapsechild.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:54:50 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/12 16:07:20 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_collapsechild(t_rtnode *parent, t_rtnode *node)
{
	t_rtnode	**tmp;

	if (!parent || !node)
		return (NULL);
	tmp = &(node->childs);
	while (*tmp)
	{
		*(tmp->parent) = parent;
		*tmp = *(tmp->next);
	}
	*(tmp->next) = parent->childs;
	parent->childs = node->childs;
	return (tree_delchild(parent, node));
}
