/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:16:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 15:56:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int			rt_quit(t_rt *rt)
{
	int		ret;

	if (!rt)
		return (-1);
	if (rt->state & RTS_MGLW_INIT)
		mglw_close();
	if ((ret = rt_check_error(rt)))
		return (ret);
	return (0);
}
