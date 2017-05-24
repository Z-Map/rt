/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:01:12 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/24 21:40:41 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt_object.h"
#include "rt_tree.h"
#include "rt_parser.h"


t_rtnode		*findn(t_rtnode *node, int (*f)(void *env), t_rtnode **nxt)
{
	t_rtnode	*ret;
	RT_DBGM("recursive.");

	if (!node)
		return (NULL);
	if ((!nxt || (*nxt != node)) && f(node->content))
		return (node);
	while (nxt && ((*nxt)->parent != *nxt) && (!(*nxt)->next))
		*nxt = node->parent;
	ret = NULL;
	if (node->childs)
		ret = findn(node->childs, f, NULL);
	if (!ret)
		ret = findn(node->next, f, NULL);
	RT_DBGM("end recursive");
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
	RT_DBGM("THE END");

	return (ret);
}
