/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:04:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 10:15:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"

static void		trans_dim(t_mat3x2f *b, t_mattf *mat, t_v3f v)
{
	t_v3f nv;

	if ((v.x == INFINITY) || (v.x == -INFINITY))
		nv = (t_v3f){(mat->x.x != 0.0) ? v.x : 0.0f,
			(mat->x.y != 0.0) ? v.x : 0.0f, (mat->x.z != 0.0f) ? v.x : 0.0f};
	else
		nv = v3fmulv3f(mat->x, nv3f(v.x));
	if ((v.y == INFINITY) || (v.y == -INFINITY))
		nv = (t_v3f){(mat->y.x != 0.0) ? v.y : nv.x,
			(mat->y.y != 0.0) ? v.y : nv.y, (mat->y.z != 0.0f) ? v.y : nv.z};
	else
		pv3faddv3f(&nv, v3fmulv3f(mat->y, nv3f(v.y)));
	if ((v.z == INFINITY) || (v.z == -INFINITY))
		nv = (t_v3f){(mat->z.x != 0.0) ? v.z : nv.x,
			(mat->z.y != 0.0) ? v.z : nv.y, (mat->z.z != 0.0f) ? v.z : nv.z};
	else
		pv3faddv3f(&nv, v3fmulv3f(mat->z, nv3f(v.z)));
	b->x.x = mxminf(nv.x, b->x.x);
	b->y.x = mxminf(nv.y, b->y.x);
	b->z.x = mxminf(nv.z, b->z.x);
	b->x.y = mxmaxf(nv.x, b->x.y);
	b->y.y = mxmaxf(nv.y, b->y.y);
	b->z.y = mxmaxf(nv.z, b->z.y);
}

t_mat3x2f		bound_transform(t_mat3x2f b, t_mattf m)
{
	t_mat3x2f	nb;

	nb = b;
	trans_dim(&nb, &m, (t_v3f){b.x.x, b.y.x, b.z.x});
	trans_dim(&nb, &m, (t_v3f){b.x.y, b.y.x, b.z.x});
	trans_dim(&nb, &m, (t_v3f){b.x.y, b.y.y, b.z.x});
	trans_dim(&nb, &m, (t_v3f){b.x.y, b.y.y, b.z.y});
	trans_dim(&nb, &m, (t_v3f){b.x.x, b.y.y, b.z.y});
	trans_dim(&nb, &m, (t_v3f){b.x.x, b.y.x, b.z.y});
	trans_dim(&nb, &m, (t_v3f){b.x.y, b.y.x, b.z.y});
	trans_dim(&nb, &m, (t_v3f){b.x.x, b.y.y, b.z.x});
	nb.x = (t_v2f){nb.x.x + m.offset.x, nb.x.y + m.offset.x};
	nb.y = (t_v2f){nb.y.x + m.offset.y, nb.y.y + m.offset.y};
	nb.z = (t_v2f){nb.z.x + m.offset.z, nb.z.y + m.offset.z};
	return (nb);
}

static int		bound_rcdim(t_v2f rd, t_v3f nor, t_v2f b, t_rtrgd *gd)
{
	t_v2f		lim;

	if (rd.y != 0.0f)
		lim = sortv2f((t_v2f){(b.x - rd.x) / rd.y, (b.y - rd.x) / rd.y});
	else
	{
		lim = (t_v2f){b.x - rd.x, b.y - rd.x};
		return (((lim.x > 0.0) || (lim.y < 0.0)) ? 0 : 1);
	}
	if ((lim.y < gd[0].depth) || (lim.x > gd[1].depth))
		return (0);
	if (lim.x > gd[0].depth)
	{
		gd[0].depth = lim.x;
		gd[0].hit_nor = (rd.y > 0.0f) ? v3fmulv3f(nor, nv3f(-1.0f)) : nor;
		gd[0].flags |= RAY_GDEPTH | RAY_GHNOR;
	}
	if (lim.y < gd[1].depth)
	{
		gd[1].depth = lim.y;
		gd[1].hit_nor = (rd.y > 0.0f) ? nor : v3fmulv3f(nor, nv3f(-1.0f));
		gd[1].flags |= RAY_GDEPTH | RAY_GHNOR;
	}
	return (1);
}

int				bound_raycast(t_rtray *r, t_mat3x2f b, t_rtrgd *gd)
{
	if (!bound_rcdim((t_v2f){r->start.x, r->direction.x},
			(t_v3f){1.0f, 0.0f, 0.0f}, b.x, gd) || (gd[1].depth < 0.0f))
		return (0);
	if (!bound_rcdim((t_v2f){r->start.y, r->direction.y},
			(t_v3f){0.0f, 1.0f, 0.0f}, b.y, gd) || (gd[1].depth < 0.0f))
		return (0);
	if (!bound_rcdim((t_v2f){r->start.z, r->direction.z},
			(t_v3f){0.0f, 0.0f, 1.0f}, b.z, gd) || (gd[1].depth < 0.0f))
		return (0);
	return (1);
}

int				bound_lraycast(t_rtray *r, t_mat3x2f b, t_rtrgd *gd)
{
	t_ul		flags[2];
	int			ret;

	flags[0] = gd[0].flags;
	flags[1] = gd[1].flags;
	gd[0].flags &= ~(RAY_GDEPTH | RAY_GHNOR);
	gd[1].flags &= ~(RAY_GDEPTH | RAY_GHNOR);
	ret = bound_raycast(r, b, gd);
	if (gd[0].flags & RAY_GDEPTH)
		gd[0].flags |= RAY_GLOCAL;
	else
		gd[0].flags = flags[0];
	if (gd[1].flags & RAY_GDEPTH)
		gd[1].flags |= RAY_GLOCAL;
	else
		gd[1].flags = flags[1];
	return(ret);
}
