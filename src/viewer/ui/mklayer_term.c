/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:27:35 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/26 15:28:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_term.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_term			*mklayer_term(t_v2f pos, t_v2f dim, t_v4i color,\
int placement)
{
	t_layer_term		*term;

	if (!(term = malloc(sizeof(t_layer_term))))
		return (0);
	term->pos = (t_v2f){pos.x, pos.y};
	term->dim = (t_v2f){dim.x, dim.y};
	term->color = (t_v4f){color.x, color.y, color.z, color.w};
	term->gen.placement = placement;
	term->gen.show = 1;
	term->gen.event = 1;
	return (term);
}

void					mklayer_main_term(t_layer_term *term, int size)
{
	term->term = mkterm(size);
}

t_rtnode				*mknlayer_term(t_v2f pos, t_v2f dim, t_v4i color,\
int placement)
{
	t_layer_term		*term;
	t_rtnode			*node;

	if (!(term = mklayer_term(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(term));
	node->type = TE_TERM;
	node->flags = get_id_ui_node();
	return (node);
}
