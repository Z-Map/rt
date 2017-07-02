/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_loadbar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 13:55:35 by alhelson          #+#    #+#             */
/*   Updated: 2017/07/02 18:10:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_loadbar		*mklayer_loadbar(t_v2f pos, t_v2f dim, t_v4i color[3],\
	int placement)
{
	t_layer_loadbar	*load;

	if (!(load = malloc(sizeof(t_layer_loadbar))))
		return (0);
	load->pos = (t_v2f){pos.x, pos.y};
	load->dim = (t_v2f){dim.x, dim.y};
	load->color[0] = (t_v4f){color[0].x, color[0].y, color[0].z, color[0].w};
	load->color[1] = (t_v4f){color[1].x, color[1].y, color[1].z, color[1].w};
	load->color[2] = (t_v4f){color[2].x, color[2].y, color[2].z, color[2].w};
	load->gen[0].placement = PL_LEFT;
	load->gen[0].show = 1;
	load->gen[0].event = 0;
	load->gen[1].placement = PL_RIGHT;
	load->gen[1].show = 1;
	load->gen[1].event = 0;
	load->gen[2].placement = placement;
	load->gen[2].show = 1;
	load->gen[2].event = 0;
	load->load = 0.0;
	return (load);
}

t_rtnode			*mknlayer_loadbar(t_v2f pos, t_v2f dim, t_v4i color[3],\
	int placement)
{
	t_layer_loadbar	*load;
	t_rtnode		*node;

	if (!(load = mklayer_loadbar(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(load));
	node->type = TE_LOADBAR;
	node->flags = get_id_ui_node();
	return (node);
}
