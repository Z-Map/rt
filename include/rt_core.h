/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:08:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 22:02:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CORE_H
# define RT_CORE_H

# include <pthread.h>
# include "mglw/mglw.h"

# include "rt_prototype.h"
# include "data/rt_data_core.h"

# ifdef RT_DEBUG
extern t_rt	*g_rt_root;
#  define RT_DBGI __LINE__, __FILE__, __func__
#  define RT_DBGP(code, name) rtd_point(g_rt_root, code, name, RT_DBGI)
#  define RT_DBGR(rcode, code, msg) rtd_ret(g_rt_root, rcode, code, msg, RT_DBGI)
#  define RT_DBGM(msg) rtd_msg(g_rt_root, RT_DBGM_GLOBALE, msg, RT_DBGI)
#  define RT_DBGMC(mask, msg) rtd_msg(g_rt_root, mask, msg, RT_DBGI)
# else
#  define RT_DBGP(code, name) code
#  define RT_DBGR(rcode, code, msg) rcode
#  define RT_DBGM(msg) 0
#  define RT_DBGMC(mask, msg) 0
# endif

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

int			rt_error(t_rt *rt, int code, const char *msg);
int			rt_check_error(t_rt *rt);

int			rt_quit(t_rt *rt);

#endif
