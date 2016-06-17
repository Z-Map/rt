/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 14:14:20 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/17 14:14:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "rt.h"

t_obj			*rt_obj_init(t_obj *obj, t_type type);
t_obj			*rt_obj_nparent(t_obj *obj, unsigned int n);
t_obj			*rt_obj_addchild(t_obj *parent, t_obj *child);
t_obj			*rt_obj_delchild(t_obj *parent, t_obj *child);
t_obj			*rt_obj_getcamera(t_obj *obj);
t_obj			*rt_obj_rotate(t_obj *obj, const t_v4d radians);
t_obj			*rt_obj_byid(t_obj *node, const unsigned int id);

#endif