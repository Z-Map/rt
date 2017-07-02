/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:06:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:50:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_parser.h"
#include "rt_render.h"
#include "rt_core.h"

int			rt_init_scenerdr(t_rt *rt)
{
	rt_state(rt, RTS_INIT, RT_SET);
	if (!(rt->tree = parse_scene(rt->scene)))
		return (rt_error(-118, "Parsing fail."));
	rt_init_rdrmgrthread(rt);
	return (1);
}

int			rt_init_mglw(t_rt *rt)
{
	if (!mglw_init())
		return (rt_error(-121, "Unable to init mglw."));
	if (!(rt->viewer.rdrtarget = mglw_mkimage((int)rt->render.render_size.x,
		(int)rt->render.render_size.y, MGLW_RGBA, MGLWI_USERALLOC)))
		return (rt_error(-122, "Render image allocation fail."));
	rt_state(rt, RTS_MGLW_INIT, RT_SET);
	if ((rt->flags & RT_VISUALPREV) ||
		!(rt->flags & (RT_FILEOUT | RT_COMMANDMODE)))
		rt_init_viewerthread(rt);
	return (1);
}

int			rt_run(t_rt *rt)
{
	if (rt->state & RTS_VPREV)
		rt_sync_viewerthread(rt);
	if (rt_state(rt, RTS_RDRMGR_INIT, RT_GET))
		rt_sync_rdrmgrthread(rt);
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

	ret = rt_init_mglw(rt);
	if (ret)
		ret = rt_init_scenerdr(rt);
	if (ret <= 0)
		return (ret);
	rdrmgr_render_request(rt, rt->tree);
	while (rt_isrunning(rt))
		ret = rt_run(rt);
	return (ret);
}
