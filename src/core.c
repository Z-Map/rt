/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:06:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 21:54:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt.h"

int			rt_init_scenerdr(t_rt *rt)
{
	rt_state(rt, RTS_INIT, RT_SET);
	RT_DBGM("Start tree parsing.");
	rt->tree = sda_parser(rt->scene);
	RT_DBGM("Tree parsed.");
	print_tree(rt->tree);
	rt_init_rdrmgrthread(rt);
	RT_DBGM("Render inited.");
	return (1);
}

int			rt_init_mglw(t_rt *rt)
{
	if (!mglw_init())
		return (rt_error(rt, 121, "Unable to init mglw."));
	rt_state(rt, RTS_MGLW_INIT, RT_SET);
	rt_init_viewerthread(rt);
	RT_DBGM("MGLW inited.");
	return (1);
}

int			rt_run(t_rt *rt)
{
	if (rt->state & RTS_VPREV)
		rt_sync_viewerthread(rt);
	if (!(rt->flags & RT_MODES))
		rt_state(rt, RTS_QUIT, RT_SET);
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
	return (ret);
}
