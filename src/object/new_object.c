/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:51:21 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/15 21:32:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_object.h"

static void			init_obj(t_rtobj *obj, t_rtobt type, const char *name)
{
	*obj = (t_rtobj){
		.type = type,
		.color = (t_rgba){.r = 200, .g = 200, .b = 200, .a = 255},
		.flags = 0,
		.usercfg = 0,
		.name = name
	};
}

t_rtobj			*mkobject(t_rtobt type, const char *name)
{
	t_rtobj		*newob;

	if (!(type & VALID) || !(newob = (t_rtobj *)malloc(obj_type_memsize(type))))
		return (NULL);
	init_obj(newob, type, name);
	return (newob);
}

int				mkobjects(t_rtobj **obtab, size_t num, ...)
{
	va_list		objs;
	size_t		i;

	va_start(objs, num);
	i = 0;
	while (i < num)
	{
		if (!(obtab[i] = mkobject(va_arg(objs, t_rtobt), NULL)))
			break ;
		i++;
	}
	va_end(objs);
	if (i != num)
	{
		while (i)
			rmobject(obtab[i--]);
		return (0);
	}
	return (1);
}

t_rtobi			*mkinstance(t_rtobj *object, char *name)
{
	t_rtobi		*newinst;

	if (!object || !(newinst = malloc((t_rtobi *)sizeof(t_rtobi))))
		return (NULL);
	newinst->obdata = object;
	object->instances += 1;
	return (newinst);
}

int				mkinstances(t_rtobi **obitab, size_t num, ...)
{
	va_list		objs;
	size_t		i;

	va_start(objs, num);
	i = 0;
	while (i < num)
	{
		if (!(obitab[i] = mkinstance(va_arg(objs, t_rtobj *), NULL)))
			break ;
		i++;
	}
	va_end(objs);
	if (i != num)
	{
		while (i)
			rminstance(obitab[i--]);
		return (0);
	}
	return (1);
}
