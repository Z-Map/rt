/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 21:07:42 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/23 03:42:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJECTS_H
#define RT_OBJECTS_H

# include <stdarg.h>

# include "rt_prototype.h"
# include "data/rt_data_objects.h"
# include "data/rt_data_core.h"

# define RTOBJ_MEMBUF_SIZE		128
# define RTOBI_MEMBUF_SIZE		128



size_t			obj_type_memsize(t_rtobt type);

t_rtobj			*mkobject(t_rtobt type, const char *name);
int				mkobjects(t_rtobj **obtab, size_t num, ...);
int				rmobject(t_rtobj *obj);
int				rmobjects(size_t num, ...);

t_rtobi			*mkinstance(t_rtobj *object, char *name);
int				mkinstances(t_rtobi **obitab, size_t num, ...);
t_rtobj			*rminstance(t_rtobi *inst);
int				rminstances(size_t num, ...);

void			object_default(t_rtobj *object);


#endif
