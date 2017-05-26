/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 21:07:42 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/26 14:47:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJECTS_H
# define RT_OBJECTS_H

# include <stdarg.h>

# include "rt_prototype.h"
# include "data/rt_data_objects.h"
# include "rt_core.h"

# define RTOBJ_MEMBUF_SIZE		128
# define RTOBI_MEMBUF_SIZE		128

size_t			obj_type_memsize(t_rtobt type);
int				obj_type_search(t_rtobt type);
int				obj_typename_search(const char *name);

t_rtobj			*mkobject(t_rtobt type, const char *name);
int				mkobjects(t_rtobj **obtab, size_t num, ...);
int				rmobject(t_rtobj *obj);
int				rmobjects(size_t num, ...);

t_rtmat			*mkmaterial(const char *name);
int				mkmaterials(t_rtmat **mattab, size_t num, ...);
int				rmmaterial(t_rtmat *mat);
int				rmmaterials(size_t num, ...);

t_rtobi			*mkinstance(t_rtobj *object, char *name);
int				mkinstances(t_rtobi **obitab, size_t num, ...);
t_rtobj			*rminstance(t_rtobi *inst);
int				rminstances(size_t num, ...);

void			object_default_scene(t_rtobd *object);
void			object_default_empty(t_rtobd *object);
void			object_default_camera(t_rtobd *object);
void			object_default_plan(t_rtobd *object);
void			object_default_sphere(t_rtobd *object);
void			object_default_cone(t_rtobd *object);
void			object_default_cylinder(t_rtobd *object);
void			object_default_cuboid(t_rtobd *object);
void			object_default_tris(t_rtobd *object);
void			object_default_mesh(t_rtobd *object);
void			object_default_light(t_rtobj *obj);
void			object_default_sunlight(t_rtobd *object);
void			object_default_pointlight(t_rtobd *object);
void			object_default_spot(t_rtobd *object);
void			object_default(t_rtobj *object);
void			obinst_default(t_rtobi *inst, t_rtobj *obj, const char *name);

t_mat3x2f		object_bound_cuboid(t_rtobd *ob);
t_mat3x2f		object_bound_cone(t_rtobd *ob);
t_mat3x2f		object_bound_cylinder(t_rtobd *ob);
t_mat3x2f		object_bound_sphere(t_rtobd *ob);
t_mat3x2f		object_bound_tris(t_rtobd *ob);
t_mat3x2f		object_bound_mesh(t_rtobd *ob);
t_mat3x2f		object_bound_plan(t_rtobd *ob);
t_mat3x2f		object_getbound(t_rtobj *obj);
t_mat3x2f		instance_getbound(t_rtobi *ob, const t_mattf *m);

void			object_set(t_rtobj *object, FT_CC *vn, t_rt vt, void *vc);
void			object_getsetter(t_rtobt type);

#endif
