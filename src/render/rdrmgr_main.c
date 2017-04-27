/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrmgr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 01:42:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/26 15:57:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

int			rdrmgr_isalive(t_rt *rt)
{
	if (!rt_isrunning(rt))
		return (0);
	return (1);
}


void		*rdrmgr_exit(t_rt *rt, int code)
{
	return (NULL);
}

void		*rt_rdrmgr_main(void *arg)
{
	t_rt		*rt;

	rt = (t_rt *)arg;
	while (rdrmgr_isalive(rt))
	{
		// Le rendu commence ici
		rdrmgr_sync(rt);
	}
	pthread_exit(rdrmgr_exit(rt, 0));
}
