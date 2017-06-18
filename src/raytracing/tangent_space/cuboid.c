/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:12:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 20:08:41 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_cuboid(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	rdata->lgeo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_cuboid(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	rdata->lgeo.hit_tangent = geo_cubic_tangentspace(rdata->lgeo.hit_nor,
		(t_v3f){1.0, 0.0, 0.0}, (t_v3f){0.0, 1.0, 0.0}, (t_v3f){0.0, 0.0, 1.0});
	// rdata->geo.hit_tangent = geo_cubic_tangentspace(rdata->geo.hit_nor,
	// 	rdata->geo.node->transform.x, rdata->geo.node->transform.y,
	// 	rdata->geo.node->transform.z);
	rdata->lgeo.flags |= RAY_GHTANG;
	// rdata->geo.flags |= RAY_GHTANG;
	return (1);
}

t_v2f		getuv_cuboid(t_rtrgd gd)
{
	t_v2f	uv;
	t_v3f	v;
	t_v3i	a;

	v = (t_v3f){mxabsf(gd.hit_nor.x), mxabsf(gd.hit_nor.y),
		mxabsf(gd.hit_nor.z)};
	a.x = (v.z > v.x) ? 1 : 0;
	a.y = (v.z > v.y) ? 1 : 0;
	a.z = (v.y > v.x) ? 1 : 0;
	if (a.x & a.y)
		uv = (t_v2f){gd.hit_point.x, gd.hit_point.y};
	else if (!(a.x | a.z))
		uv = (t_v2f){gd.hit_point.z, gd.hit_point.y};
	else
		uv = (t_v2f){gd.hit_point.x, gd.hit_point.z};
	return (uv);
}
