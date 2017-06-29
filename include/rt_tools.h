/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 01:52:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/29 18:21:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TOOL_H
# define RT_TOOL_H

# include "rt_prototype.h"
# include "rt_core.h"
# include "data/rt_data_objects.h"
# include "data/rt_data_tree.h"
# include "data/rt_data_render.h"
# include "data/rt_data_viewer.h"

t_mat3x2f		bound_transform(t_mat3x2f b, t_mattf m);
int				bound_isvalid(t_mat3x2f b);
t_mat3x2f		bound_union(t_mat3x2f a, t_mat3x2f b);
t_mat3x2f		bound_intersect(t_mat3x2f a, t_mat3x2f b);
t_mat3x2f		no_bound(void);
t_mat3x2f		infinity_bound(void);
int				bound_raycast(t_rtray *r, t_mat3x2f b, t_rtrgd *gd);

t_rtray			ray_trans(t_rtray ray, t_mattf m);
t_v3f			ray_hitpoint(t_rtray ray, float depth);
t_rtray			ray_bounceto(t_rtrgd geo, t_v3f dir);
t_rtray			ray_transmit(t_rtrgd geo, t_v3f dir);

int				intersect_depth(t_rtrgd *gd, t_rtray r, t_v2f d);
int				geo_setdepth(t_rtrgd *gd, int dim, float depth);
void			geo_gnor(t_rtrd *rdata);
void			geo_tan(t_rtrd *rdata);
t_rtrgd			geo_getglobal(t_rtrgd gd, t_rtray r);
t_mat2x3f		geo_cubic_tangentspace(t_v3f nor, t_v3f x, t_v3f y, t_v3f z);
t_v2f			geo_uv(t_rtrd *rd);

#endif
