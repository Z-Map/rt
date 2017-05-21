/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:51:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/21 18:44:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"

#ifdef RT_DEBUG
t_rt		*g_rt_root = NULL;
#endif

int			rt_init_main(t_rt *rt)
{
	#ifdef RT_DEBUG
	g_rt_root = rt;
	#endif
	*rt = (t_rt){ .global_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER,
		.flags = RT_VISUALPREV,
		.state = 0, .error = 0,
		.scene = "data/scenes/default.sda",
		.fileout = NULL,
		.viewer = (t_rtview){ .keys = 0,
			.win = NULL, .wins = NULL, .layer = NULL },
		.render = (t_rtr) { .flags = 0, .target = NULL,
			.render_size = (t_v2ui){1400, 900}, .render_px = NULL},
		.debug = (struct s_debugger){
			.flags = RT_DBGF_MSG, // | RT_DBGF_RET | RT_DBGF_RETCP,
			.mask = RT_DBGM_GLOBALE,
			.codepoint = 0, .cpline = 0, .cpname = NULL, .cpfile = NULL,
			.cpfunc = NULL}
	};
	ft_bzero(rt->errors, sizeof(rt->errors));
	RT_DBGM("RT started.");
	return (1);
}
