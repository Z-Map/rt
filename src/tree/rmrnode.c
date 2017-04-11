/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:34:30 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/11 18:49:43 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int				rmrnode(t_rtnode *node)
{
	t_rtnode	**tmp;

	if (!node)
		return (0);
	tmp = &(node->childs);
	while (*tmp)
	{
		rmrnodes(*tmp);
		rmnode(*tmp);
	}
	rmnode(node);
	return (1);
}
