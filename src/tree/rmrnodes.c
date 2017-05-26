/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmrnodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:51:13 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/19 19:18:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

int			rmrnodes(size_t num, ...)
{
	va_list	nodes;

	if (num == 0)
		return (0);
	va_start(nodes, num);
	while (num-- > 0)
		rmrnode(va_arg(nodes, t_rtnode **));
	va_end(nodes);
	return (1);
}
