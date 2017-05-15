/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:51:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 07:30:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"

int			rt_init_main(t_rt *rt)
{
	*rt = (t_rt){ .global_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER,
		.flags = 0, .state = 0, .error = 0, .scene = NULL, .fileout = NULL,
		.viewer = (t_rtview){ .keys = 0,
			.win = NULL, .wins = NULL, .layer = NULL },
		.render = (t_rtr) { .flags = 0, .target = NULL,
			.render_size = (t_v2ui){0,0}, .render_px = NULL},
#ifdef RT_DEBUG
		.debug = (struct s_debugger){
			.flags = RT_DBGF_MSG|RT_DBGF_RET,
			.mask = RT_DBGM_GLOBALE,
			.codepoint = 0, .cpline = 0, .cpname = NULL, .cpfile = NULL,
			.cpfunc = NULL}
#endif
	};
	ft_bzero(rt->errors, sizeof(rt->errors));
	RT_DBGM(rt, "RT started.")
	return (1);
}
