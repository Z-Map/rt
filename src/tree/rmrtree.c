/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrtree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:35:47 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/25 21:39:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

int				rmrtree(t_rtree **tree)
{
	t_rtnode	*nod;

	if (!tree || !*tree)
		return (0);
	nod = (*tree)->node.childs;
	if (nod)
	{
		nod = nod->next;
		rmrnode(&((*tree)->node.childs));
		(*tree)->node.childs = nod;
	}
	if ((*tree)->buffer)
		free((*tree)->buffer);
	rmnode((t_rtnode **)tree);
	return (1);
}
