/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:57:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/15 21:17:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_object.h"

int				rmobject(t_rtobj *obj)
{
	if (obj)
		free(obj);
	else
		return (0);
	return (1);
}

int				rmobjects(size_t num, ...)
{
	va_list		objs;
	size_t		i;
	int			ret;

	va_start(objs, num);
	i = 0;
	ret = 1;
	while (i < num)
	{
		if (!rmobject(va_arg(objs, t_rtobj *)))
			ret = 0;
	}
	va_end(objs);
	return (ret);
}

void			delinstance(t_rtobi *inst)
{
	t_rtobj		*ob;

	ob = rminstance(inst);
	if (ob && !(ob->instances))
		rmobject(ob);
}

t_rtobj			*rminstance(t_rtobi *inst)
{
	t_rtobj		*ob;

	if (!inst)
		return (NULL);
	ob = inst->obdata;
	if (ob)
		ob->instances -= 1;
	free(inst);
	return (ob);
}

int				rminstances(size_t num, ...)
{
	va_list		objs;
	size_t		i;
	int			ret;

	va_start(objs, num);
	i = 0;
	ret = 1;
	while (i < num)
	{
		if (!rminstance(va_arg(objs, t_rtobi *)))
			ret = 0;
	}
	va_end(objs);
	return (0);
}
