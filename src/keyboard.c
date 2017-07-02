/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:23:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:32:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "rt_tree.h"
#include "rt_object.h"
#include "rt_core.h"
#include "rt_ui.h"

static int	key_press_extend(t_rt *rt, int k)
{
	if (k == MGLW_KEY_F)
		rt->flags ^= RTF_FILTER;
	else
		return (0);
	rt->flags |= RTF_RDRREFRESH;
	rt->viewer.keys |= RTWK_REFRESH;
	return (1);
}

int			rt_keypress(void *env, int k)
{
	t_rt	*rt;

	rt = (t_rt *)env;
	if (key_press_extend(rt, k))
		return (0);
	if (k == MGLW_MOUSE_BUTTON_1)
	{
		event_ui(rt);
		return (0);
	}
	else if (k == MGLW_MOUSE_BUTTON_3)
	{
		event_noclick_variator(rt);
		return (0);
	}
	rt = rt_keyboard_camera(env, k);
	if (!rt)
		return (0);
	rt->flags |= RTF_RDRREFRESH;
	rt->viewer.keys |= RTWK_REFRESH;
	return (0);
}

int			rt_keyrelease(void *env, int k)
{
	t_rt	*rt;

	rt = (t_rt *)env;
	if (k == MGLW_MOUSE_BUTTON_1)
	{
		event_noclick_variator(rt);
		return (1);
	}
	return (0);
}
