/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:15:50 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:50:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int				rt_error(int code, const char *msg)
{
	static t_rt	*rt = NULL;

	if (!code)
	{
		if (!rt && msg)
			rt = (t_rt *)(t_ul)msg;
		return (0);
	}
	if (!rt)
		return (-1);
	if (msg)
		ft_printf("Error #%i : \"%s\"\n", code, msg);
	rt->error = code;
	if (code < 0)
	{
		pthread_mutex_lock(&(rt->state_lock));
		rt->state |= RTS_QUIT;
		pthread_mutex_unlock(&(rt->state_lock));
	}
	return (code);
}

int				rt_check_error(t_rt *rt)
{
	if (!rt)
		return (-1);
	return (rt->error);
}
