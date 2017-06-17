/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:26:37 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:24:37 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "mathex/vector.h"
#include "rt_tools.h"
#include "rt_render.h"

float		shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree)
{
	t_rtrd	rdata;

	rdata = shadowtrace(ray_bounceto(geo, *(t_v3f *)(&l.v)), l, tree, 3);
	return (rdata.frag.color.w * l.pwr);
}
