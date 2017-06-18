/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/18 18:58:33 by ealbert          ###   ########.fr       */
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
	
	rdata = shadowtrace(ray_bounceto(geo, *(t_v3f *)(&l.v)), l, tree, 3);
	return (*pv3fmulv3f((t_v3f *)&rdata.frag.color, nv3f(rdata.frag.color.w)));
}
