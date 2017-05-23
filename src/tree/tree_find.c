/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:01:12 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/23 03:47:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*tree_find_next_iteration(t_rtnode *node, int (*f)(void *env))
{
	while (node)
	{
		if (f(node->content))
			return (node);
		tree_find_next_iteration(node->childs, f);
		node = node->next;
	}
	tree_find_next_iteration(node->parent->next, f);
	return (NULL);
}

t_rtnode		*tree_find_first_iteration(t_rtnode *node, int (*f)(void *env))
{
	while (node)
	{
		if (f(node->content))
			return (node);
		tree_find_first_iteration(node->childs, f);
		node = node->next;
	}
	return (NULL);
}

t_rtnode		*tree_find(t_rtnode *node, int (*f)(void *env))
{
	t_rtnode	*ret;

	ret = NULL;
	if (!node)
		return (NULL);
	if (node->parent == node)
		ret = tree_find_first_iteration(node->childs, f);
	else
		ret = tree_find_next_iteration(node->childs, f);
	return (ret);
}
