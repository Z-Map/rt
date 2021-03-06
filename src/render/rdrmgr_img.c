/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 00:59:04 by lcarreel          #+#    #+#             */
/*   Updated: 2017/07/03 00:59:17 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "rt_render.h"

static t_v4f		calc_pixel(t_ui x, t_ui y, t_rtrmgr *rmgr)
{
	t_rtrd			rd;
	t_rayd			rayd;

	rayd.ray = rdr_pxray(x, y, rmgr,
		(t_rtrnode *)(rmgr->rendertree->tree.camera));
	rayd.tree = rmgr->rendertree;
	rayd.lim = (t_v2f){0.0, INFINITY};
	rayd.transmission = 6;
	rayd.reflecion = 4;
	rd = raytrace(&rayd);
	return (rd.frag.color);
}

int					render_worker(t_ui px, t_ui step, t_rt *rt, t_rtrmgr *rmgr)
{
	const size_t	mlen = rmgr->rsize.x * rmgr->rsize.y;
	int				get;
	t_ui			i;
	t_ui			n;

	n = px;
	while ((px < mlen)
		&& ((get = rdrmgr_isrendering(rt, rmgr)) > RTRMGR_FINISHED))
	{
		i = px / rmgr->rsize.x;
		rmgr->rpx[px] = calc_pixel(px % rmgr->rsize.x, i, rmgr);
		px += step;
		rt->render.advance[n] = (float)px / (float)mlen;
	}
	if (get > RTRMGR_FINISHED)
		get = RTRMGR_FINISHED;
	return (get);
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
