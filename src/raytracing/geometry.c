/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 21:13:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 09:51:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			ray_setgeo(t_rayd *rayd, t_rtrgd gd)
{
	int		i;
	int		ret;
	t_rtrgd	tmp;
	t_rtrgd	*tab;

	if ((gd.depth <= rayd->lim.x) || (gd.depth > rayd->lim.y))
		return (0);
	i = 0;
	ret = 0;
	tab = rayd->geostack;
	while (i < RDR_GEOSTACK)
	{
		tmp = tab[i];
		if (gd.depth < tab[i].depth)
		{
			gd.flags |= RAY_GVALID;
			tmp = gd;
			gd = tab[i];
			ret = 1;
		}
		tab[i] = tmp;
	}
	return (ret);
}
