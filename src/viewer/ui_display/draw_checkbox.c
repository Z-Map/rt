/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_checkbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:19:50 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:20:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void					draw_checkbox(mglwin *img, t_layer_checkbox *cb)
{
	t_v4f				color;
	mglrect				rect_d;

	color = cb->color2;
	if (cb->state)
		color = cb->color;
	rect_d = gen_to_rect(cb->gen, color);
	mgl_drawrect(img, rect_d);
}
