/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_variator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:03:09 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/24 21:03:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_variator		*mklayer_variator(t_v2f pos, t_v2f dim,\
t_v4i color[2], int placement)
{
	t_layer_variator	*variator;

	if (!(variator = malloc(sizeof(t_layer_variator))))
		return (0);
	variator->pos = (t_v2f){pos.x, pos.y};
	variator->dim = (t_v2f){dim.x, dim.y};
	variator->color[0] = (t_v4i){color[0].x,\
	color[0].y, color[0].z, color[0].w};
	variator->color[1] = (t_v4i){color[1].x, color[1].y,\
	color[1].z, color[1].w};
	variator->gen[0].placement = placement;
	variator->gen[0].show = 1;
	variator->gen[0].event = 1;
	variator->gen[1].placement = PL_LEFT;
	variator->gen[1].show = 1;
	variator->gen[1].event = 1;
	variator->load = 0.5;
	return (variator);
}

t_rtnode				*mknlayer_variator(t_v2f pos, t_v2f dim,\
t_v4i color[2], int placement)
{
	t_layer_variator	*variator;
	t_rtnode			*node;

	if (!(variator = mklayer_variator(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(variator));
	node->type = TE_VARIATOR;
	node->flags = get_id_ui_node();
	return (node);
}
