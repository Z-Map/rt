/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_to_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:55:43 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/29 18:55:27 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"
#include "mglw/data/rect.h"
#include "mathex/color.h"

mglrect		gen_to_rect(t_layer_gen gen, t_v4f color)
{
	mglrect	rect_d;
	t_v4f	col;

	rect_d = (mglrect){.flags = 0, .border_left = 0, .border_right = 0,
		.border_top = 0, .border_bottom = 0};
	rect_d.position[0] = (float)(gen.pos.x);
	rect_d.position[1] = (float)(gen.pos.y);
	rect_d.size[0] = (float)(gen.dim.x);
	rect_d.size[1] = (float)(gen.dim.y);
	rect_d.shadow[0] = 0;
	rect_d.shadow[1] = 0;
	rect_d.shadow[2] = 0;
	rect_d.border_color = 0;
	rect_d.shadow_color = 0;
	col = (t_v4f){
		color.x / 255.0, color.y / 255.0, color.z / 255.0, color.w / 255.0};
	rect_d.color = v4ftoui(col);
	return (rect_d);
}
