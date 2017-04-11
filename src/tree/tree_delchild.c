/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_delchild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:05:08 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/10 19:15:35 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_delchild(t_rtnode *parent, t_rtnode *node)
{
	t_rtnode	**tmp;

	tmp = &(parent->childs);
	if (!parent || !node)
		return (NULL);
	while (*tmp && (*tmp != node))
		tmp = &((*tmp)->next);
	if (!*tmp)
		return (NULL);
	*tmp = node->next;
	node->next = NULL;
	node->parent = NULL;
}
