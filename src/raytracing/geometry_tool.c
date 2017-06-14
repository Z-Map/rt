/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:56:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 19:28:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"

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
	gtan = (int (*)(t_rtobd *, t_rtrd *))(lgd->inst->obj->get_tan);
	if ((lgd->flags & RAY_GHNOR) || !gtan)
		return ;
	gtan((t_rtobd *)(lgd->inst->obj), rdata);
}
