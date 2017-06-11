/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:39:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/12 00:14:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/vector.h"
#include "mathex/utils.h"
#include "rt_texture.h"

t_v4f			rtex_nocol(t_rtex *tex, t_v2f uv)
{
	(void)tex;
	(void)uv;
	return ((t_v4f){1.0f, 0.1f, 0.4f, 1.0f});
}

t_v3f			rtex_nonor(t_rtex *tex, t_v2f uv)
{
	(void)tex;
	(void)uv;
	return ((t_v3f){0.0f, 0.0f, 1.0f});
}

static t_v2f	mkuv(t_v2f uv, t_v2ui ims)
{
	if (uv.x < 0.0f)
		uv.x = ceilf(-uv.x) + uv.x;
	else
		uv.x = fmodf(uv.x, 1.0f);
	if (uv.y < 0.0f)
		uv.y = ceilf(-uv.y) + uv.y;
	else
		uv.y = fmodf(uv.y, 1.0f);
	uv.x *= (float)ims.x;
	uv.y *= (float)ims.y;
	return (uv);
}

t_v4f			rtex_uvimage_col(t_rtex *tex, t_v2f uv)
{
	mglimg		*t;
	t_v2ui		uvi;
	t_v4f		cols[4];

	t = tex->img;
	uv = mkuv(uv, (t_v2ui){t->x, t->y});
	uvi = (t_v2ui){(t_ui)(uv.x) % t->x, (t_ui)(uv.y) % t->y};
	cols[0] = rgbatov4f(((t_rgba *)(t->pixels))[uvtolen(uvi, t->x)]);
	// return (cols[0]);
	uvi.x = (uvi.x + 1) % t->x;
	cols[1] = rgbatov4f(((t_rgba *)(t->pixels))[uvtolen(uvi, t->x)]);
	uvi = (t_v2ui){(t_ui)(uv.x) % t->x, (uvi.y + 1) % t->y};
	cols[2] = rgbatov4f(((t_rgba *)(t->pixels))[uvtolen(uvi, t->x)]);
	uvi.x = (uvi.x + 1) % t->x;
	cols[3] = rgbatov4f(((t_rgba *)(t->pixels))[uvtolen(uvi, t->x)]);
	uv = (t_v2f){fmodf(uv.x,1.0f), fmodf(uv.y,1.0f)};
	cols[0] = v4faddv4f(v4fmulv4f(cols[0], nv4f((1.0f - uv.x))),
		v4fmulv4f(cols[1], nv4f(uv.x)));
	cols[1] = v4faddv4f(v4fmulv4f(cols[2], nv4f(1.0f - uv.x)),
		v4fmulv4f(cols[3], nv4f(uv.x)));
	return (v4faddv4f(v4fmulv4f(cols[0], nv4f((1.0f - uv.y))),
		v4fmulv4f(cols[1], nv4f(uv.y))));
}

t_v3f			rtex_uvimage_nor(t_rtex *tex, t_v2f uv)
{
	t_v4f		v;

	v = rtex_uvimage_col(tex, uv);
	pv4fmulv4f(pv4fsubv4f(&v, nv4f(0.5f)), nv4f(2.0f));
	return(*((t_v3f *)&v));
}
