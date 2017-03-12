/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:15:50 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 15:39:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

// static void	error_push(t_rt *rt)
// {
// 	int		*errors;
// 	int		tmp;
// 	int		i;
//
// 	i = 14
// 	errors = rt->errors;
// 	while (i-- && *errors)
// 		errors[]
// }

int			rt_error(t_rt *rt, int code, const char *msg)
{
	if (!code)
		return (0);
	if (!rt)
		return (-1);
	if (msg)
		ft_printf("Error #%i : \"%s\"\n", code, msg);
	// if (rt->error)
	rt->error = code;
	if (code < 0)
	{
		pthread_mutex_lock(&(rt->state_lock));
		rt->state |= RTS_QUIT;
		pthread_mutex_unlock(&(rt->state_lock));
	}
	return (code);
}

int			rt_check_error(t_rt *rt)
{
	if (!rt)
		return (-1);
	return (0);
}
