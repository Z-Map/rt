/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:42:55 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 22:43:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

static int			is_border(t_layer_border *b, int x, int y)
{
	int				vx;
	int				vy;

	vx = b->dim_border * b->gen.dim.x;
	vy = b->dim_border * b->gen.dim.y;
	if (y < vy && (b->valid_border & 1))
		return (1);
	if (x < vx && (b->valid_border & 2))
		return (1);
	if (x >= b->gen.dim.x - vx && (b->valid_border & 4))
		return (1);
	if (y >= b->gen.dim.y - vy && (b->valid_border & 8))
		return (1);
	return (0);
}

void				draw_border(mglimg *img, t_layer_border *grid)
{
	int				cx;
	int				cy;
	unsigned int	index;

	cx = 0;
	cy = 0;
	while (cy < grid->gen.dim.y)
	{
		while (cx < grid->gen.dim.x)
		{
			if (is_border(grid, cx, cy))
			{
				index = img->x * (grid->gen.pos.y + cy) * 4 +\
				(grid->gen.pos.x + cx) * 4;
				add_rgb_in_img(img, index, grid->color);
			}
			cx++;
		}
		cy++;
		cx = 0;
	}
}
