/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:49:55 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 23:03:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_border			*mklayer_border(t_v2f pos, t_v2f dim, t_v4i color,\
int placement)
{
	t_layer_border		*border;

	if (!(border = malloc(sizeof(t_layer_border))))
		return (0);
	border->pos = (t_v2f){pos.x, pos.y};
	border->dim = (t_v2f){dim.x, dim.y};
	border->color = (t_v4i){color.x, color.y, color.z, color.w};
	border->valid_border = 15;
	border->dim_border = 0.02;
	border->gen.show = 1;
	border->gen.event = 0;
	border->gen.placement = placement;
	return (border);
}

t_rtnode				*mknlayer_border(t_v2f pos, t_v2f dim, t_v4i color,\
int placement)
{
	t_layer_border		*border;
	t_rtnode			*node;

	if (!(border = mklayer_border(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(border));
	node->type = TE_BORDER;
	node->flags = get_id_ui_node();
	return (node);
}
