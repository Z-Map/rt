/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <fanno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 08:23:49 by fanno             #+#    #+#             */
/*   Updated: 2017/05/26 08:23:49 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

// Actuellement cette feature tourne sous la lib MLX. Je vais l'adapter asap
/*
void			adapt_pixel(t_win *win, int color, int x, int y)
{
	unsigned int	stock;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				value;

	value = y * win->img.sl + x * (win->img.bpp >> 3);
	if (y < 0 || x < 0 || y >= win->height || x >= win->width)
		return;
	stock = mlx_get_color_value(win->mlx, color);
	red = ((stock & 0xFF0000) >> 16);
	green = ((stock & 0xFF00) >> 8);
	blue = (stock & 0xFF);
	(win->img.data)[value] = blue;
	(win->img.data)[value + 1] = green;
	(win->img.data)[value + 2] = red;
}

static int		loading(double nb_line, t_win *win)
{
	int		x;
	int		y;
	float	nb;

	nb = nb_line / win->height * 100;
	x = win->width / 2 -200;
	y = win->height / 2;
	while (y <= win->height / 2 + 20)
	{
		while (x < win->width / 2 + 200)
		{
			if (y == win->height / 2 || y == win->height / 2 + 20)
				adapt_pixel(win, 16777215, x, y);
			if (x > win->width /.2 - 200 && x < win->width / 2 + 200 && x % 10)
				if (nb > 0 && y != win->height / 2 && y < win->height / 2 + 19)
					if (x < (win->width / 2 - 200) + 400 * nb / 100)
						adapt_pixel(win, 0xD40028, x, y);
			x++;
		}
		x = win->width / 2 - 200;
		adapt_pixel(win, 16777215, x, y);
		adapt_pixel(win, 16777215, win->width / 2 + 200, y);
		y++;
	}
	return (0);
}

void			calc_line(t_win *win)
{
	int		i;
	int		cp;

	cp = 0;
	i = 0;
	while (i < win->height)
	{
		if (win->calc_line[i])
			cp++;
		i++;
	}
	loading(cp, win);
}*/
