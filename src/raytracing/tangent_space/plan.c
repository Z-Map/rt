/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:11:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 17:54:23 by qloubier         ###   ########.fr       */
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
	(void)rdata;
	return (1);
}
