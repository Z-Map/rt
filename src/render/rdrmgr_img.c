/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:56:32 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/12 15:42:01 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

static t_rgba		calc_pixel(t_rt *rt)
{
	t_rgba			rgba;

	rgba = (t_rgba){'0', '0', '0', '0'};
	rt = NULL; // A FAIRE
	return (rgba);
}

int					img_calc(t_rt *rt, t_rtrmgr *rmgr)
{
	unsigned int	x;
	unsigned int	y;
	int				get;

	x = 0;
	while (x < (*rmgr).rsize.x)
	{
		y = 0;
		while (y < (*rmgr).rsize.y)
		{
			(*rmgr).rpx[x * (*rmgr).rsize.x + y] = calc_pixel(rt);
			get = rdrmgr_isrendering(rt, rmgr);
			if (get & RTRMK_STOP)
				return (rt_error(rt, 1, "Render quit"));
			else if (get & RTRMK_CANCEL)
				return (8);
			y++;
		}
		x++;
	}
	return (1);
}
