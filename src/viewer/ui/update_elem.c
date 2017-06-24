/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:16:50 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/24 21:17:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"

void		update_loadbar(t_layer_loadbar *load, t_layer_gen *gen_father)
{
	t_v2f	dim[2];

	dim[0].x = load->load;
	dim[1].x = 1.0 - dim[0].x;
	dim[0].y = 1.0;
	dim[1].y = 1.0;
	update_pos(gen_father, &(load->gen[2]), load->pos, load->dim);
	update_pos(&(load->gen[2]), &(load->gen[0]), load->pos, dim[0]);
	update_pos(&(load->gen[2]), &(load->gen[1]), load->pos, dim[1]);
}

void		update_variator(t_layer_variator *var, t_layer_gen *gen_father)
{
	t_v2f	dim;
	t_v2f	pos;

	dim.x = var->dim.x * 0.05; // size of 5%
	dim.y = 1.0; //dimension de la bar
	pos.x =  var->load;
	pos.y = 0.0;
	update_pos(gen_father, &(var->gen[0]), var->pos, var->dim);
	update_pos(&(var->gen[0]), &(var->gen[1]), pos, dim);
}
