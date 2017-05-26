/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:35:47 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/19 19:34:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_tree.h"

int				rmtree(t_rtree **tree)
{
	if (!tree || !*tree)
		return (0);
	if ((*tree)->buffer)
		free((*tree)->buffer);
	rmnode((t_rtnode **)&tree);
	return (1);
}
