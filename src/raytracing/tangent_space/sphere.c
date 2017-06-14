/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:03:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 17:50:11 by qloubier         ###   ########.fr       */
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
	(void)ob;
	(void)rdata;
	return (1);
}
