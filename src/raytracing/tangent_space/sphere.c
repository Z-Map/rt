/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:03:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 19:22:37 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_sphere(t_rtobd *ob, t_rtrd *rdata)
{
	rdata->lgeo.hit_nor = v3fdivv3f(*(t_v3f *)&(rdata->lgeo.hit_point),
		nv3f(ob->sphere.radius));
	rdata->lgeo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_sphere(t_rtobd *ob, t_rtrd *rdata)
{
	t_v3f	v;
	float	a;

	(void)ob;
	if ((v.x != 0.0) || (v.y != 0.0))
	{
		v = rdata->lgeo.hit_nor;
		v.z = cosf(acosf(v.z) + M_PI_2);
		a = 1.0 - (v.z * v.z) / len3f((t_v3f){v.x, v.y, 0.0});
		v = (t_v3f){v.x * a, v.y * a, v.z};
	}
	else
		v = (t_v3f){1.0, 0.0, 0.0};
	if (rdata->lgeo.hit_nor.z < 0.0)
		v = (t_v3f){-v.x, -v.y, v.z};
	rdata->lgeo.hit_tangent.x = v;
	rdata->lgeo.hit_tangent.y = normalized3f(v3fcrossv3f(v,
		rdata->lgeo.hit_nor));
	rdata->lgeo.flags |= RAY_GHTANG;
	return (1);
}

t_v2f		getuv_sphere(t_rtrgd gd)
{
	return (nortouv(gd.hit_nor));
}
