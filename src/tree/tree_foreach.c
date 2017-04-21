/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:50:20 by ealbert           #+#    #+#             */
/*   Updated: 2017/04/21 20:55:16 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FAILURE -1
# define INFIX 1
# define PREFIX 2
# define SUFFIX 3

#include "rt_tree.h"

static int	infix_foreach(t_rtnode *node, int (*f)(t_rtnode *, void *),
	void *env)
{
	t_rtnode	**tmp;

	tmp = &node;
	while (*tmp)
	{
		if ((*tmp)->childs)
			infix_foreach((*node)->childs, f, env);
		if (f(tmp, env) == FAILURE)
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
		if (tmp->childs)
			prefix_foreach(tmp->childs, f, env);
		tmp = &(tmp->next);
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

int tree_foreach(t_rtnode *node, int method, int (*f)(t_rtnode *, void *),
	void *env)
{
	if (method & INFIX)
		return (infix_foreach(node, f, env));
	else if (method & SUFFIX)
		return (suffix_foreach(node, f, env));
	else if (method & PREFIX)
		return (suffix_foreach(node, f, env));
	return (FAILURE);
}
