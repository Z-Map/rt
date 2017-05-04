/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:08:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/04 12:13:48 by qloubier         ###   ########.fr       */
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

int			rt_error(t_rt *rt, int code, const char *msg);
int			rt_check_error(t_rt *rt);

int			rt_quit(t_rt *rt);

#endif
