/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:35:47 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/18 15:44:24 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

int				rmtree(t_rtree *tree)
{
	t_rtnode	**tmp;
	t_rtnode	**next;

	if (!tree)
		return (0);
	tmp = &(tree->node.childs);
	next = NULL;
	while (*tmp)
	{
		*next = (*tmp)->next;
		rmrnode(*tmp);
		*tmp = *next;
	}
	if (tree->buffer)
		free(tree->buffer);
	free(tree);
	tree = NULL;
	return (1);
}
