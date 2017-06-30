/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_addchild_wid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 23:01:32 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 23:01:56 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

int				tree_addchild_wid(t_rtnode *tree, t_rtnode *node, int id)
{
	t_rtnode	*tmp;
	t_rtnode	*tmp2;

	if (!(tmp = tree_found_node_with_id(tree, id)))
		return (0);
	if (!(tmp2 = tree_addchild(tmp, node)))
		return (0);
	return (1);
}
