/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:34:30 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/12 19:07:26 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int				rmrnode(t_rtnode *node)
{
	t_rtnode	**tmp;
	t_rtnode	**next;

	if (!node)
		return (0);
	tmp = &(node->childs);
	while (*tmp)
	{
		rmrnodes(*tmp);
		*next = tmp->next;
		rmnode(*tmp);
		*tmp = *next;
	}
	rmnode(node);
	return (1);
}
