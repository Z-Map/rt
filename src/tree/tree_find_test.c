/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:01:12 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/24 20:24:44 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

t_rtnode		*findn(t_rtnode *node, int (*f)(void *env), t_rtnode **nxt)
{
	t_rtnode	*ret;
	t_rtnode	*it;

	if ((!nxt || (*nxt != node)) && f(node->content))
		return (node);
	while (nxt && ((*nxt)->parent != *nxt) && (!(*nxt)->next))
		*nxt = node->parent;
	ret = NULL;
	it = node->childs;
	while (!ret && it)
	{
		ret = findn(it, f, NULL);
		it = it->next;
	}
	if (!ret)
		ret = findn(node->next, f, NULL);
	return (ret);
}

t_rtnode		*tree_find(t_rtnode *node, int (*f)(void *env))
{
	t_rtnode	*ret;
	t_rtnode	*it;

	ret = NULL;
	if (!node)
		return (NULL);
	it = node;
	while (!ret && node)
	{
		ret = findn(node, f, &it);
		node = it->next;
	}
	return (ret);
}
