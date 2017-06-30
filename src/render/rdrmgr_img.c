/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:56:32 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/30 09:52:39 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "rt_render.h"

static t_v4f		calc_pixel(t_ui x, t_ui y, t_rtrmgr *rmgr)
{
	t_rtrd			rd;
	t_rayd			rayd;
	// t_v3f			col;

	rayd.ray = rdr_pxray(x, y, rmgr,
		(t_rtrnode *)(rmgr->rendertree->tree.camera));
	rayd.tree = rmgr->rendertree;
	rayd.lim = (t_v2f){0.0, INFINITY};
	rayd.transmission = 6;
	rayd.reflecion = 4;
	rd = raytrace(&rayd);
	// col = v3faddv3f(v3fmulv3f(rd.geo.hit_tangent.y, nv3f(0.5f)), nv3f(0.5f));
	return (rd.frag.color);
}

int					render_worker(t_ui px, t_ui step, t_rt *rt, t_rtrmgr *rmgr)
{
	const size_t	mlen = rmgr->rsize.x * rmgr->rsize.y;
	int				get;
	t_ui			i;

	while ((px < mlen)
		&& ((get = rdrmgr_isrendering(rt, rmgr)) > RTRMGR_FINISHED))
	{
		i = px / rmgr->rsize.x;
		rmgr->rpx[px] = calc_pixel(px % rmgr->rsize.x, i, rmgr);
		px += step;
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
