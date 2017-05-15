/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:50:20 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/15 16:58:55 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

static int	infix_foreach(t_rtnode *node, int (*f)(t_rtnode *, void *),
	void *env)
{
	t_rtnode	**tmp;

	tmp = &node;
	while (*tmp)
	{
		if ((*tmp)->childs)
			infix_foreach(node->childs, f, env);
		if (f(*tmp, env) == FAILURE)
			return (FAILURE);
		*tmp = (*tmp)->next;
	}
	return (1);
}

static int	prefix_foreach(t_rtnode *node, int (*f)(t_rtnode *, void *),
	void *env)
{
	t_rtnode	**tmp;

	tmp = &node;
	while (*tmp)
	{
		if (f(node, env) == FAILURE)
			return (FAILURE);
		if ((*tmp)->childs)
			prefix_foreach((*tmp)->childs, f, env);
		tmp = &((*tmp)->next);
	}
	return (1);
}

static int	suffix_foreach(t_rtnode *node, int (*f)(t_rtnode *, void *),
	void *env)
{
	if (node->childs)
		suffix_foreach(node->childs, f, env);
	if (node->next)
		suffix_foreach(node->next, f, env);
	if (f(node, env) == FAILURE)
		return (FAILURE);
	return (1);
}

int			tree_foreach(t_rtnode *node, int method,
		int (*f)(t_rtnode *, void *), void *env)
{
	if (method & INFIX)
		return (infix_foreach(node, f, env));
	else if (method & SUFFIX)
		return (suffix_foreach(node, f, env));
	else if (method & PREFIX)
		return (prefix_foreach(node, f, env));
	return (FAILURE);
}
