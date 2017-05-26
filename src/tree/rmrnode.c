/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:34:30 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/19 19:17:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int				rmrnode(t_rtnode **node)
{
	t_rtnode	*tmp;
	t_rtnode	*next;

	if (!node || !*node)
		return (0);
	next = (*node)->childs;
	while (next)
	{
		tmp = next;
		next = next->next;
		rmrnode(&tmp);
	}
	rmnode(node);
	return (1);
}
