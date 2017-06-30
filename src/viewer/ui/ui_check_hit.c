/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_check_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:14:27 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:25:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

int				ui_is_event(t_layer_gen gen)
{
	if (gen.event)
		return (1);
	return (0);
}

int				ui_check_hit(t_rtnode *node, t_v2i *pos_cursor)
{
	t_layer_gen	gen;

	if (node->type == TE_VARIATOR)
		gen = ((t_layer_variator *)(node->content))->gen[1];
	else if (node->type == TE_LOADBAR)
		return (0);
	else
		gen = ((t_layer_root *)(node->content))->gen;
	if (pos_cursor->x < gen.pos.x + gen.dim.x && pos_cursor->x > gen.pos.x &&\
	pos_cursor->y < gen.pos.y + gen.dim.y && pos_cursor->y > gen.pos.y)
		return (1);
	return (0);
}
