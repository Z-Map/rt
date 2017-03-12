/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:51:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 16:23:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rt_viewer.h"

int					rt_init_window(t_rt *rt)
{
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	rt->viewer.layer = (mglimg *)mglw_get2dlayer(rt->viewer.win);
	ft_bzero(rt->viewer.layer->pixels, rt->viewer.layer->memlen);
	return (0);
}

void			*rt_viewer_main(void *arg)
{
	t_rt		*rt;

	rt = (t_rt *)arg;
	if (rt_init_window(rt))
		pthread_exit(NULL);
	while (42)
	{
		if (!rt_isrunning(rt) || !(rt->state & RTS_VPREV))
		{
			mglwin_shouldclose(rt->viewer.win);
			break ;
		}
		viewer_loop(rt);
	}
	rt->state &= ~RTS_VPREV;
	pthread_exit(NULL);
}
