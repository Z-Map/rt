/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:10:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/22 16:21:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "mathex/utils.h"
#include "rt_tree.h"
#include "rt_object.h"
#include "rt_core.h"
#include "rt_viewer.h"

int			rt_mousemove(void *env, double x, double y)
{
	t_rt	*rt;

	rt = (t_rt *)env;
	rt->viewer.mouse = (t_v2f){
		mxrangef((float)x, 0.0, (float)(rt->viewer.win->data->screen_w)),
		mxrangef((float)y, 0.0, (float)(rt->viewer.win->data->screen_h))};
	if (rt->viewer.layer_event_focus)
	{
		event_onclick_variator(rt);
		rt->viewer.keys |= RTWK_REFRESH;
	}
	return (0);
}
