/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:47:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/30 12:34:24 by qloubier         ###   ########.fr       */
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

/*
** # define SHADOWLIMIT 1000.0f
*/

void		*rt_rdrmgr_main(void *arg);
int			rdrmgr_isalive(t_rt *rt);
int			rdrmgr_sync(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_done(t_rt *rt, t_rtrmgr *rmgr);
void		*rdrmgr_exit(t_rt *rt, t_rtrmgr *rmgr);
int			rdrmgr_isrendering(t_rt *rt, t_rtrmgr *rmgr);

int			rdrmgr_render_request(t_rt *rt, t_rtree *tree);

int			intersect_cylinder(t_rayd *rayd, t_rtobd *cy, t_rtrgd *gd);
int			intersect_sphere(t_rayd *rayd, t_rtobd *sphere, t_rtrgd *gd);
int			intersect_cuboid(t_rayd *rayd, t_rtobd *o, t_rtrgd *gd);
int			intersect_plan(t_rayd *rayd, t_rtobd *plan, t_rtrgd *gd);
int			intersect_cone(t_rayd *rayd, t_rtobd *cone, t_rtrgd *gd);
int			intersect_tris(t_rayd *rayd, t_rtobd *cone, t_rtrgd *gd);
int			intersect_mesh(t_rayd *rayd, t_rtobd *plan, t_rtrgd *gd);

int			getnor_cylinder(t_rtobd *ob, t_rtrd *rdata);
int			gettan_cylinder(t_rtobd *ob, t_rtrd *rdata);
int			getnor_sphere(t_rtobd *ob, t_rtrd *rdata);
int			gettan_sphere(t_rtobd *ob, t_rtrd *rdata);
int			getnor_cuboid(t_rtobd *ob, t_rtrd *rdata);
int			gettan_cuboid(t_rtobd *ob, t_rtrd *rdata);
int			getnor_plan(t_rtobd *ob, t_rtrd *rdata);
int			gettan_plan(t_rtobd *ob, t_rtrd *rdata);
int			getnor_cone(t_rtobd *ob, t_rtrd *rdata);
int			gettan_cone(t_rtobd *ob, t_rtrd *rdata);
int			getnor_tris(t_rtobd *ob, t_rtrd *rdata);
int			gettan_tris(t_rtobd *ob, t_rtrd *rdata);
int			getnor_mesh(t_rtobd *ob, t_rtrd *rdata);
int			gettan_mesh(t_rtobd *ob, t_rtrd *rdata);

t_v2f		getuv_sphere(t_rtrgd gd);
t_v2f		getuv_cuboid(t_rtrgd gd);
t_v2f		getuv_cylinder(t_rtrgd gd);

int			ray_setgeo(t_rayd *rayd, t_rtrgd gd);

t_rtrfd		shade_sky(t_rtrd *rdata, t_rdrtree *tree);
t_rtrfd		shade_diffuse(t_rtrd *rdata, t_rtmat *mat, t_rdrtree *tree);
t_v3f		shade_normale(t_rtrd *rdata, t_rtmat *mat);
t_rtrfd		shade_reflect(t_rtrd *rdata, t_rtmat *mat, t_rdrtree *tree);
t_v3f		shade_lightsloop(t_rtrgd geo, t_rdrtree *tree);
t_v3f		shade_sunlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree);
t_v3f		shade_light(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree);
t_v3f		shade_spotlight(t_rtrgd geo, t_rtrnode *nod, t_rdrtree *tree);

t_rtrd		shadow_transmit(t_rtrd rdata, t_rdrtree *tree, t_ui raycount);
t_rtrd		shadowtrace(t_rtray ray, t_rtrld l, t_rdrtree *tree, t_ui raycount);
t_v3f		shadow_test(t_rtrgd geo, t_rtrld l, t_rdrtree *tree);

t_rtray		rdr_pxray(t_ui x, t_ui y, t_rtrmgr *rmgr, t_rtrnode *camnode);

int			rdr_raycast(t_rayd *rayd, t_rdrtree *tree);
t_rtrfd		rdr_shade(t_rtrd rdata, t_rdrtree *tree);
t_rtrd		rdr_transmit(t_rtrd rdata, t_rayd *rayd, t_ui num);
t_rtrd		raysky(t_rtrd rdata, t_rayd *rayd);
t_rtrd		rayshade(t_rtrd rdata, t_rtrgd gd, t_rayd *rayd, t_ui num);
t_rtrd		raytrace(t_rayd *rayd);

t_rtrd		rdr_filter(t_rtrfd frag, t_rtree *tree);
int			img_calc(t_rt *rt, t_rtrmgr *rmgr);

t_mat3d		kernel_which(int knl);
t_v4f		*kernel_calc(t_v4f *img, t_mat3d knl, t_v2ui max);

int			render_worker(t_ui px, t_ui step, t_rt *rt, t_rtrmgr *rmgr);
int			rdr_start_workers(t_rt *rt, t_rtrmgr *mgr);

void		filter_apply(t_rtrmgr *rmgr);

#endif
