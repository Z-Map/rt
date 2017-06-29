/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:23:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/29 16:21:45 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "rt_tree.h"
#include "rt_object.h"
#include "rt_core.h"
#include "rt_ui.h"

int			rt_keypress(void *env, int k)
{
	t_rt	*rt;

	rt = (t_rt *)env;
	if (k == MGLW_MOUSE_BUTTON_1)
	{
		event_ui(rt);
		return (0);
	}
	// desactivation du variator : fail
	else if (k == MGLW_MOUSE_BUTTON_3)
	{
		event_noclick_variator(rt);
		return (0);
	}
	rt = rt_keyboard_camera(env, k);
	if (rt)
		rt->flags |= RTF_RDRREFRESH;
	return (0);
}

int			rt_keyrelease(void *env, int k)
{
	t_rt	*rt;

	rt = (t_rt *)env;
	(void)k;
	return (0);
}
