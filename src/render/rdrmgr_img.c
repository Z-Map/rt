/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:56:32 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/23 03:53:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_render.h"

static t_rgba		calc_pixel(t_ui x, t_ui y, t_rtrmgr *rmgr)
{
	t_rtrd			rd;

	RT_DBGM("coucou !");
	rd = raytrace(x, y, rmgr, rmgr->rendertree);
	return (rd.color);
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
			rmgr->rpx[(y * rmgr->rsize.x) + x] = calc_pixel(x, y, rmgr);
			if ((get = rdrmgr_isrendering(rt, rmgr)) < RTRMGR_FINISHED)
				return (get);
			y++;
		}
		x++;
	}
	return (RTRMGR_FINISHED);
}
