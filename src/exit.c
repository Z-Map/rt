/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:16:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 06:59:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int			rt_quit(t_rt *rt)
{
	int		ret;

	if (!rt)
		return (-1);
	if (rt_state(rt, RTS_VPREV, RT_GET))
		rt_sync_viewerthread(rt);
	if (rt_state(rt, RTS_RDRMGR_INIT, RT_GET))
		rt_sync_rdrmgrthread(rt);
	if (rt_state(rt, RTS_MGLW_INIT, RT_UNSET))
		mglw_close();
	if ((ret = rt_check_error(rt)))
		return (ret);
	return (0);
}
