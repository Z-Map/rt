/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 01:52:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 22:42:39 by qloubier         ###   ########.fr       */
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

#endif
