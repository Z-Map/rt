/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 16:40:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

t_v3f		shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree)
{
	t_rtrd	rdata;
	t_v3f	pwr;
	t_rayd	rayd;

	rayd.ray = ray_bounceto(geo, *(t_v3f *)(&l.v));
	rayd.tree = tree;
	rayd.lim = (t_v2f){0.0, l.depth};
	rayd.transmission = 0;
	rayd.reflecion = 0;
	l.color = rgbatov3f(l.ob->pointlight.color);
	rdata = shadowtrace(&rayd, l);
	// rdata.frag.color.w = 1.0;
	pwr = nv3f(rdata.frag.color.w * l.pwr);
	return (*pv3fmulv3f((t_v3f *)&rdata.frag.color, pwr));
	// return (nv3f(l.pwr));
}
