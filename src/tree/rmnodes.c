/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmnodes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:30:19 by lcarreel          #+#    #+#             */
/*   Updated: 2017/04/11 17:41:10 by lcarreel         ###   ########.fr       */
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
		if (node)
		{
			free(node);
			node = NULL;
		}
	return (1);
}
