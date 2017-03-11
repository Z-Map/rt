/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:15:50 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/11 18:30:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int			rt_error(t_rt *rt, int code, const char *msg)
{
	if (!rt)
		return (-1);
	ft_printf("Error #%i : %s\n", code, msg);
	return (code);
}

int			rt_check_error(t_rt *rt)
{
	if (!rt)
		return (-1);
	return (0);
}
