/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:56:32 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/21 19:30:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

static t_rgba		calc_pixel(t_rt *rt)
{
	t_rgba			rgba;

	rgba = (t_rgba){255, 0, 0, 255};
	(void)rt;
	return (rgba);
}

int					img_calc(t_rt *rt, t_rtrmgr *rmgr)
{
	unsigned int	x;
	unsigned int	y;
	int				get;

	x = 0;
	while (x < rmgr->rsize.x)
	{
		y = 0;
		while (y < rmgr->rsize.y)
		{
			rmgr->rpx[(y * rmgr->rsize.x) + x] = calc_pixel(rt);
			if ((get = rdrmgr_isrendering(rt, rmgr)) < RTRMGR_FINISHED)
				return (get);
			y++;
		}
		x++;
	}
	return (RTRMGR_FINISHED);
}
