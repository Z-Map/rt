/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:29:22 by ghubert           #+#    #+#             */
/*   Updated: 2017/06/29 18:58:37 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

void		filter_apply(t_rtrmgr *rmgr)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos;
	t_v4f			color;

	color = rgbatov4f(rmgr->filter.color);
	y = 0;
	while (y < rmgr->rsize.y)
	{
		x = 0;
		while (x < rmgr->rsize.x)
		{
			pos = x + (y * rmgr->rsize.x);
			rmgr->rpx[pos].x += (color.x * color.w);
			rmgr->rpx[pos].y += (color.y * color.w);
			rmgr->rpx[pos].z += (color.z * color.w);
			x++;
		}
		y++;
	}
}
