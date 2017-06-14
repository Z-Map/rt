/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 09:12:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/13 17:50:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"
#include "rt_render.h"

int			getnor_cuboid(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	rdata->lgeo.flags |= RAY_GHNOR;
	return (1);
}

int			gettan_cuboid(t_rtobd *ob, t_rtrd *rdata)
{
	(void)ob;
	(void)rdata;
	return (1);
}
