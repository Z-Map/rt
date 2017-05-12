/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:47:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 16:34:34 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# include <pthread.h>

# include "rt_prototype.h"
# include "rt_core.h"

# include "data/rt_data_render.h"

void		*rt_rdrmgr_main(void *arg);
int			rdrmgr_isalive(t_rt *rt);
int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr);
void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr, int code);
int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr);
int			img_calc(t_rt *rt, t_rtrmgr *rmgr);
#endif
