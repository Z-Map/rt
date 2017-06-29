/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:58:22 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 20:12:50 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_rect		*mklayer_rect(t_v2f pos, t_v2f dim, t_v4i color,\
		int placement)
{
	t_layer_rect	*rect;

	if (!(rect = malloc(sizeof(t_layer_rect))))
		return (0);
	rect->pos = (t_v2f){pos.x, pos.y};
	rect->dim = (t_v2f){dim.x, dim.y};
	rect->color = (t_v4f){color.x, color.y, color.z, color.w};
	rect->gen.placement = placement;
	rect->gen.show = 1;
	rect->gen.event = 0;
	return (rect);
}

t_rtnode			*mknlayer_rect(t_v2f pos, t_v2f dim, t_v4i color,\
	int placement)
{
	t_layer_rect	*rect;
	t_rtnode		*node;

	if (!(rect = mklayer_rect(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(rect));
	node->type = TE_RECT;
	node->flags = get_id_ui_node();
	return (node);
}
