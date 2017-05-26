/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:24:29 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/19 19:09:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

int			rmnode(t_rtnode **node)
{
	if (!node || !*node)
		return (0);
	free(*node);
	*node = NULL;
	return (1);
}
