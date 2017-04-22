/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:34:30 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/18 15:39:14 by lcarreel         ###   ########.fr       */
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
	next = NULL;
	while (*tmp)
	{
		*next = (*tmp)->next;
		rmrnode(*tmp);
		rmnode(*tmp);
		*tmp = *next;
	}
	rmnode(node);
	return (1);
}
