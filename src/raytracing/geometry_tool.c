/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:56:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:26:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/utils.h"
#include "rt_tools.h"

t_mat2x3f	geo_cubic_tangentspace(t_v3f nor, t_v3f x, t_v3f y, t_v3f z)
{
	t_v3f	v;
	t_v3i	a;

	v = (t_v3f){mxabsf(nor.x), mxabsf(nor.y), mxabsf(nor.z)};
	a.x = (v.z > v.x) ? 1 : 0;
	a.y = (v.z > v.y) ? 1 : 0;
	a.z = (v.y > v.x) ? 1 : 0;
	if (a.x & a.y)
		return ((t_mat2x3f){x, (nor.z < 0.0f) ? (t_v3f){-y.x, -y.y, -y.z} : y});
	else if (!(a.x | a.z))
		return ((t_mat2x3f){z, (nor.x < 0.0f) ? (t_v3f){-y.x, -y.y, -y.z} : y});
	else
		return ((t_mat2x3f){z, (nor.y < 0.0f) ? x : (t_v3f){-x.x, -x.y, -x.z}});
}

void		geo_gnor(t_rtrd *rdata)
{
	t_rtrgd	*lgd;
	int		(*gnor)(t_rtobd *, t_rtrd *);

	lgd = &(rdata->lgeo);
	if (!(lgd->flags & RAY_GVALID) || (lgd->flags & RAY_GHNOR))
		return ;
	gnor = (int (*)(t_rtobd *, t_rtrd *))(lgd->inst->obj->get_nor);
	if (!gnor)
		return ;
	gnor((t_rtobd *)(lgd->inst->obj), rdata);
}

void		geo_tan(t_rtrd *rdata)
{
	t_rtrgd	*lgd;
	int		(*gtan)(t_rtobd *, t_rtrd *);

	lgd = &(rdata->lgeo);
	if ((lgd->flags & RAY_GHTANG) ||
		((lgd->flags & (RAY_GVALID|RAY_GHNOR)) != (RAY_GVALID|RAY_GHNOR)))
		return ;
	if (!(lgd->flags & RAY_GINTER))
	{
		rdata->lgeo.hit_tangent = geo_cubic_tangentspace(rdata->lgeo.hit_nor,
			(t_v3f){1.0, 0.0, 0.0}, (t_v3f){0.0, 1.0, 0.0},
			(t_v3f){0.0, 0.0, 1.0});
		rdata->lgeo.flags |= RAY_GHTANG;
	}
	else
	{
		gtan = (int (*)(t_rtobd *, t_rtrd *))(lgd->inst->obj->get_tan);
		if (!gtan)
			return ;
		gtan((t_rtobd *)(lgd->inst->obj), rdata);
	}
}
