/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:47:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/02 17:57:12 by qloubier         ###   ########.fr       */
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

# define RDR_MAXWORKER 8
# define MAXLIGHTINTENSITY 3.0f
# define MARGIN 0.001f

void		*rt_rdrmgr_main(void *arg);
int			rdrmgr_isalive(t_rt *rt);
int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr);
void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr);

int			rdrmgr_render_request(t_rt *rt, t_rtree *tree);

int			intersect_cylinder(t_rtray ray, t_rtobd *cy, t_rtrgd *gd);
int			intersect_sphere(t_rtray ray, t_rtobd *sphere, t_rtrgd *gd);
int			intersect_cuboid(t_rtray ray, t_rtobd *o, t_rtrgd *gd);
int			intersect_plan(t_rtray ray, t_rtobd *plan, t_rtrgd *gd);
int			intersect_cone(t_rtray ray, t_rtobd *cone, t_rtrgd *gd);
int			intersect_tris(t_rtray ray, t_rtobd *cone, t_rtrgd *gd);
int			intersect_mesh(t_rtray ray, t_rtobd *plan, t_rtrgd *gd);

float		shade_lightsloop(t_rtrgd geo, t_rdrtree *tree);

t_rtray		rdr_pxray(t_ui x, t_ui y, t_rtrmgr *rmgr, t_rtrnode *camnode);
t_rtrgd		rdr_raycast(t_rtray ray, t_rtree *tree);
t_rtrfd		rdr_shade(t_rtrgd geometry, t_rtree *tree);
t_rtrd		rdr_filter(t_rtrfd frag, t_rtree *tree);
t_rtrd		raytrace(t_ui x, t_ui y, t_rtrmgr *mgr, t_rtree *tree);

int			img_calc(t_rt *rt, t_rtrmgr *rmgr);

int			render_worker(t_ui px, t_ui step, t_rt *rt, t_rtrmgr *rmgr);
int			rdr_start_workers(t_rt *rt, t_rtrmgr *mgr);


#endif
