/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:06:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 15:48:38 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt.h"

int			rt_init_scenerdr(t_rt *rt)
{
	rt->state = RTS_INIT;
	return (1);
}

int			rt_init_mglw(t_rt *rt)
{
	if (!mglw_init())
		return (rt_error(rt, 121, "Unable to init mglw."));
	rt->state |= RTS_MGLW_INIT;
	rt_init_viewerthread(rt);
	return (1);
}

int			rt_run(t_rt *rt)
{
	if (rt->state & RTS_VPREV)
		rt_sync_viewerthread(rt);
	if (!(rt->flags & RT_MODES))
		rt->state |= RTS_QUIT;
	return (0);
}

int			rt_isrunning(t_rt *rt)
{
	if (!(rt->state & RTS_INIT) ||
		(rt->state & RTS_QUIT))
		return (0);
	return (1);
}

int			rt_main(t_rt *rt)
{
	int		ret;

	ret = rt_init_scenerdr(rt);
	if ((rt->flags & RT_VISUALPREV) ||
		!(rt->flags & (RT_FILEOUT | RT_COMMANDMODE)))
		ret = rt_init_mglw(rt);
	if (ret <= 0)
		return (ret);
	while (rt_isrunning(rt))
		ret = rt_run(rt);
	if (rt->flags & RT_VISUALPREV)
		rt_sync_viewerthread(rt);
	return (ret);
}
