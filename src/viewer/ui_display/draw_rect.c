/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:41:58 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 22:42:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void				draw_rect(mglimg *img, t_layer_rect *rect)
{
	int				cx;
	int				cy;
	unsigned int	index;

	cx = 0;
	cy = 0;
	while (cy < rect->gen.dim.y)
	{
		while (cx < rect->gen.dim.x)
		{
			index = img->x * (rect->gen.pos.y + cy) * 4 +\
			(rect->gen.pos.x + cx) * 4;
			add_rgb_in_img(img, index, rect->color);
			cx++;
		}
		cy++;
		cx = 0;
	}
}
