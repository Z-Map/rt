/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loadbar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 13:51:08 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/23 13:52:24 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void				draw_loadbar(mglimg *img, t_layer_loadbar *loadbar)
{
	t_layer_border	border;
	t_layer_rect	rect[2];
/*
	border = (t_layer_border){.gen = loadbar->gen[2], .pos = loadbar->pos,\
	.dim = loadbar->dim, .color = loadbar->color[2],\
	.border_display = 15, .dim_border = 0.05, .valid_border = 15};
	rect[0] = (t_layer_rect){.gen = loadbar->gen[0], .pos = loadbar->pos,\
	.dim = (t_v2f){loadbar->dim.x * loadbar->load, loadbar->dim.y},\
	.color = loadbar->color[0]};
	rect[1] = (t_layer_rect){.gen = loadbar->gen[1], .pos = loadbar->pos,\
	.dim = (t_v2f){loadbar->dim.x * (1.0 * loadbar->load), loadbar->dim.y},\
	.color = loadbar->color[1]};
*/
        rect[0] = (t_layer_rect){.gen = loadbar->gen[0],\
        .color = loadbar->color[0]};
        rect[1] = (t_layer_rect){.gen = loadbar->gen[1],\
        .dim = (t_v2f){loadbar->dim.x * (1.0 * loadbar->load), loadbar->dim.y},\
        .color = loadbar->color[1]};

	draw_rect(img, &(rect[0]));
	draw_rect(img, &(rect[1]));
	draw_border(img, &border);
}
