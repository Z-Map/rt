/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:12:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 17:49:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_cylinder(t_rtobd *ob, t_rtrd *rdata)
{
	t_v3f	hitp;

	(void)ob;
	hitp = *(t_v3f*)&(rdata->lgeo.hit_point);
	rdata->lgeo.hit_nor = normalized3f((t_v3f){hitp.x, hitp.y, 0.0});
	rdata->lgeo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_cylinder(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	(void)rdata;
	return (1);
}
