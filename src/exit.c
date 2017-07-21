/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:16:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:50:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

static void	clean_viewer(t_rt *rt)
{
	rt_sync_viewerthread(rt);
}

int			rt_quit(t_rt *rt)
{
	int		ret;

	if (!rt)
		return (-1);
	if (rt->flags & RT_VISUALPREV)
		clean_viewer(rt);
	if (rt_state(rt, RTS_RDRMGR_INIT, RT_GET))
		rt_sync_rdrmgrthread(rt);
	if (rt_state(rt, RTS_MGLW_INIT, RT_UNSET))
		mglw_close();
	if (rt->tree)
		rmrtree(&(rt->tree));
	if ((ret = rt_check_error(rt)))
		return (ret);
	return (0);
}
