/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_checkbox.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:43:47 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:17:41 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_checkbox			*mklayer_checkbox(t_v2f pos, t_v2f dim,\
t_v4i color, int placement)
{
	t_layer_checkbox		*checkbox;

	if (!(checkbox = malloc(sizeof(t_layer_checkbox))))
		return (0);
	checkbox->pos = (t_v2f){pos.x, pos.y};
	checkbox->dim = (t_v2f){dim.x, dim.y};
	checkbox->color = (t_v4f){color.x, color.y, color.z, color.w};
	checkbox->color2 = (t_v4f){255.0 - color.x,\
	255.0 - color.y, 255.0 - color.z, color.w};
	checkbox->gen.placement = placement;
	checkbox->gen.show = 1;
	checkbox->gen.event = 1;
	checkbox->state = 0;
	return (checkbox);
}

t_rtnode					*mknlayer_checkbox(t_v2f pos, t_v2f dim,\
t_v4i color, int placement)
{
	t_layer_checkbox		*checkbox;
	t_rtnode				*node;

	if (!(checkbox = mklayer_checkbox(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(checkbox));
	node->type = TE_CHECKBOX;
	node->flags = get_id_ui_node();
	return (node);
}
