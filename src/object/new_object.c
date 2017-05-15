/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:51:21 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 22:45:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_object.h"

static void			init_obj(t_rtobj *obj, t_rtobt type, const char *name)
{
	*obj = (t_rtobj){ .type = type,
		.usercfg = 0, .name = ft_vsdup(name)};
	object_default(obj);
}

t_rtobj				*mkobject(t_rtobt type, const char *name)
{
	static t_vmem	*vm;
	t_rtobj			*newob;

	RT_DBGP(-5, "object vm creation");
	if (!vm)
		vm = ft_vmemnew((sizeof(t_rtobj) + sizeof(t_vmps)) * RTOBJ_MEMBUF_SIZE);
	RT_DBGP(obj_type_memsize(type), "object validation");
	if (!(type & VALID) || !(newob =
		(t_rtobj *)ft_vmemalloc(vm, (short)obj_type_memsize(type))))
		return (NULL);
	RT_DBGP(-5, "object init");
	init_obj(newob, type, name);
	RT_DBGP(1, "object created");
	return (newob);
}

int					mkobjects(t_rtobj **obtab, size_t num, ...)
{
	va_list			objs;
	size_t			i;

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

t_rtobi				*mkinstance(t_rtobj *object, char *name)
{
	static t_vmem	*vm;
	t_rtobi			*newinst;

	RT_DBGP(-5, "instance vm creation");
	if (!vm)
		vm = ft_vmemnew((sizeof(t_rtobi) + sizeof(t_vmps)) * RTOBI_MEMBUF_SIZE);
	if (!object || !(newinst =
		(t_rtobi *)ft_vmemalloc(vm, (short)sizeof(t_rtobi))))
		return (NULL);
	RT_DBGP(-5, "instance init");
	obinst_default(newinst, object, name);
	RT_DBGP(1, "instance created");
	object->instances += 1;
	return (newinst);
}

int					mkinstances(t_rtobi **obitab, size_t num, ...)
{
	va_list			objs;
	t_rtobj			*aob;
	size_t			i;

	va_start(objs, num);
	i = 0;
	while (i < num)
	{
		obitab[i] = NULL;
		aob = va_arg(objs, t_rtobj *);
		if (aob && !(obitab[i] = mkinstance(aob, NULL)))
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
