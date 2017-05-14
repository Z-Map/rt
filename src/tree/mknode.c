/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mknode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:13:38 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/09 19:16:36 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "rt_tree.h"

t_rtnode			*mknode(t_rtobi *ob_inst)
{
	t_rtnode		*node;

	if (!(node = (t_rtnode *)malloc(sizeof(t_rtnode))))
		return (NULL);
	node->parent = NULL;
	node->next = NULL;
	node->childs = NULL;
	node->content = (void *)ob_inst;
	return (node);
}
