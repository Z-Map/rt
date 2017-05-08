/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:56:32 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/08 15:57:44 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

int			img_calc(t_rt *rt, t_rtrmgr *rmgr)
{
	int		x;
	int		y;
	int		get;

	x = 0;
	while (x < (*rmgr).rsize.x)
	{
		y = 0;
		while (y < (*rmgr).rsize.y)
		{
			(*rmgr.rpx)[x * rmgr.rsize.x + y] = calc_pixel(rt);
			get = rdrmgr_isrendering(rt, &rmgr);
			if (get & RTRMK_STOP)
				return rt_error(rt, 1, "Render quit");
			else if (get & RTRMK_CANCEL)
				return (8);
			y++;
		}
		x++;
	}
}
