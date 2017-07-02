/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrtree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:35:47 by lcarreel          #+#    #+#             */
/*   Updated: 2017/07/02 14:43:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

static void		rtreeclean(t_rdrtree *tree)
{
	if (tree->lights)
		free(tree->lights);
	if (tree->negative)
		free(tree->negative);
	if (tree->visible)
		free(tree->visible);
}

int				rmrtree(t_rtree **tree)
{
	t_rtnode	*nod;

	if (!tree || !*tree)
		return (0);
	nod = (*tree)->node.childs;
	while (nod)
	{
		nod = nod->next;
		rmrnode(&((*tree)->node.childs));
		(*tree)->node.childs = nod;
	}
	if ((*tree)->node.type & TREET_RENDER)
		rtreeclean((t_rdrtree *)(*tree));
	if ((*tree)->buffer)
		free((*tree)->buffer);
	rmnode((t_rtnode **)tree);
	return (1);
}
