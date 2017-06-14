/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:12:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 18:42:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_cone(t_rtobd *ob, t_rtrd *rdata)
{
	t_v3f	hitp;
	float	a;

	(void)ob;
	a = mxabsf(((t_rtobd *)(rdata->lgeo.inst->obj))->cone.angle) / 2;
	hitp = *(t_v3f*)&(rdata->lgeo.hit_point);
	rdata->lgeo.hit_nor = v3faddv3f(v3fdivv3f(normalized3f((t_v3f){hitp.x,
		hitp.y, 0.0}), nv3f(cosf(a))), (t_v3f){0.0f, 0.0f,
		((hitp.z < 0.0) ? 1.0f : -1.0f) * sinf(a)});
	rdata->lgeo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_cone(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	(void)rdata;
	return (1);
}
