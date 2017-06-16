/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:11:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/15 21:50:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_plan(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	if (rdata->lgeo.ray.start.z < 0.0f)
	{
		rdata->lgeo.hit_nor = (t_v3f){0.0, 0.0, -1.0};
		rdata->geo.hit_nor = v3fmulv3f(rdata->lgeo.node->transform.z,
			nv3f(-1.0f));
	}
	else
	{
		rdata->lgeo.hit_nor = (t_v3f){0.0, 0.0, 1.0};
		rdata->geo.hit_nor = rdata->lgeo.node->transform.z;
	}
	rdata->lgeo.flags |= RAY_GHNOR;
	rdata->geo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_plan(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	if (rdata->lgeo.hit_nor.z < 0.0f)
	{
		rdata->lgeo.hit_tangent.x = (t_v3f){-1.0, 0.0, 0.0};
		rdata->lgeo.hit_tangent.y = (t_v3f){0.0, -1.0, 0.0};
		rdata->geo.hit_tangent.x = v3fmulv3f(rdata->lgeo.node->transform.x,
			nv3f(-1.0f));
		rdata->geo.hit_tangent.y =v3fmulv3f(rdata->lgeo.node->transform.y,
			nv3f(-1.0f));
	}
	else
	{
		rdata->lgeo.hit_tangent.x = (t_v3f){-1.0, 0.0, 0.0};
		rdata->lgeo.hit_tangent.y = (t_v3f){0.0, -1.0, 0.0};
		rdata->geo.hit_tangent.x = rdata->lgeo.node->transform.x;
		rdata->geo.hit_tangent.y = rdata->lgeo.node->transform.y;
	}
	rdata->lgeo.flags |= RAY_GHTANG;
	rdata->geo.flags |= RAY_GHTANG;
	return (1);
}
