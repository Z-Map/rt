/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:47:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 03:30:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# include <pthread.h>

# include "rt_prototype.h"
# include "rt_core.h"
# include "rt_object.h"
# include "rt_tree.h"

# include "data/rt_data_render.h"

void		*rt_rdrmgr_main(void *arg);
int			rdrmgr_isalive(t_rt *rt);
int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr);
void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr);

int			rdrmgr_render_request(t_rt *rt, t_rtree *tree);

t_rtray		rdr_pxray(t_ui x, t_ui y, t_rtrmgr *rmgr, t_rtrnode *camnode);
t_rtrgd		rdr_raycast(t_rtray ray, t_rtree *tree);
t_rtrfd		rdr_shade(t_rtrgd geometry, t_rtree *tree);
t_rtrd		rdr_filter(t_rtrfd frag, t_rtree *tree);
t_rtrd		raytrace(t_ui x, t_ui y, t_rtrmgr *mgr, t_rtree *tree);

int			img_calc(t_rt *rt, t_rtrmgr *rmgr);
#endif
