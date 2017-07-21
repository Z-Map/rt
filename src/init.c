/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:51:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:58:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"
#include "rt_ui.h"

int			rt_init_main(t_rt *rt)
{
	*rt = (t_rt){ .global_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER,
		.flags = RT_VISUALPREV,
		.state = 0, .error = 0,
		.scene = "data/scenes/default.sda",
		.fileout = NULL,
		.viewer = (t_rtview){ .keys = 0, .layer_event_focus = NULL,
			.win = NULL, .wins = NULL, .layer = NULL, .font = NULL},
		.render = (t_rtr) { .flags = 0, .target = NULL,
			.target_size = (t_v2ui){RT_DEFAULT_RSIZE_X, RT_DEFAULT_RSIZE_Y},
			.render_size = (t_v2ui){RT_DEFAULT_RSIZE_X, RT_DEFAULT_RSIZE_Y},
			.render_px = NULL}};
	ft_bzero(rt->errors, sizeof(rt->errors));
	rt_error(0, (const char *)rt);
	return (1);
}
