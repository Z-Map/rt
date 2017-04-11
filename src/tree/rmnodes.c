/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmnodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:30:19 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/11 18:14:56 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int			rmnodes(size_t num, ...)
{
	va_list	nodes;

	if (num == 0)
		return (0);
	va_start(nodes, num);
	while (num-- > 0)
		rmnode(va_arg(nodes, t_rtnode *));
	return (1);
}
