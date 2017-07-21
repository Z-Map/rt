/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:08:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:48:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CORE_H
# define RT_CORE_H

# include <pthread.h>
# include "mglw/mglw.h"

# include "rt_prototype.h"
# include "data/rt_data_core.h"

int			rt_main(t_rt *rt);

int			rt_init_main(t_rt *rt);
int			rt_init_scenerdr(t_rt *rt);

int			rt_init_rdrmgrthread(t_rt *rt);
int			rt_sync_rdrmgrthread(t_rt *rt);

int			rt_init_mglw(t_rt *rt);
int			rt_init_viewerthread(t_rt *rt);
int			rt_sync_viewerthread(t_rt *rt);

int			rt_run(t_rt *rt);
int			rt_isrunning(t_rt *rt);
int			rt_state(t_rt *rt, t_ul state, int s);

int			rtd_point(t_rt *rt, int code, const char *name,
				int l, const char *file, const char *func);
int			rtd_ret(t_rt *rt, int retcode, int code, const char *msg,
				int l, const char *file, const char *func);
int			rtd_msg(t_rt *rt, unsigned long mask, const char *msg,
				int l, const char *file, const char *func);

int			rt_keypress(void *env, int k);
int			rt_keyrelease(void *env, int k);
t_rt		*rt_keyboard_camera(t_rt *rt, int k);
int			rt_mousemove(void *env, double x, double y);
void		rt_resize(void *env, int x, int y);

int			rt_error(int code, const char *msg);
int			rt_check_error(t_rt *rt);

int			rt_quit(t_rt *rt);

#endif
