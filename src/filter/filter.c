/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:29:22 by ghubert           #+#    #+#             */
/*   Updated: 2017/07/03 00:29:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

void		filter_apply(t_rtrmgr *rmgr)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos;
	t_v4f			color;

	rmgr->filter.color =
		((t_rtobd *)rmgr->rendertree->tree.scene)->scene.filter;
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
