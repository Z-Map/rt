/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:01:12 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/16 16:15:45 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"
#include "rt_tree.h"
#include "rt_parser.h"

static t_rtnode	*findn(t_rtnode *node, int (*f)(void *, void *),
		t_rtnode **nxt, void *env)
{
	t_rtnode	*ret;

	if (!node)
		return (NULL);
	if ((!nxt || (*nxt != node)) && f(node->content, env))
		return (node);
	if (nxt)
		*nxt = (*nxt)->parent;
	while (nxt && ((*nxt)->parent != *nxt) && (!(*nxt)->next))
		*nxt = (*nxt)->parent;
	ret = NULL;
	if (node->childs)
		ret = findn(node->childs, f, NULL, env);
	if (!ret)
		ret = findn(node->next, f, NULL, env);
	return (ret);
}

t_rtnode		*tree_find(t_rtnode *node, int (*f)(void *, void *), void *env)
{
	t_rtnode	*ret;
	t_rtnode	*it;

	ret = NULL;
	if (!node)
		return (NULL);
	it = node;
	while (!ret && node)
	{
		ret = findn(node, f, &it, env);
		if (!it)
			break ;
		node = it->next;
	}
	return (ret);
}
