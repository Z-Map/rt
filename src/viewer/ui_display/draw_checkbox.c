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

void					draw_checkbox(mglimg *img, t_layer_checkbox *cb)
{
	int					cx;
	int					cy;
	unsigned int		index;
	t_v4i				color;

	cx = 0;
	cy = 0;
	color = cb->color2;
	if (cb->state)
		color = cb->color;
	while (cy < cb->gen.dim.y)
	{
		while (cx < cb->gen.dim.x)
		{
			index = img->x * (cb->gen.pos.y + cy) * 4 +\
			(cb->gen.pos.x + cx) * 4;
			add_rgb_in_img(img, index, color);
			cx++;
		}
		cy++;
		cx = 0;
	}
}
