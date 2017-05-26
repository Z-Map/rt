/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:06:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 17:00:53 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"

int				rt_state(t_rt *rt, t_ul state, int s)
{
	if (s == RT_GET)
		return (((rt->state & state) == state) ? 1 : 0);
	else if (((s == RT_SET) && ((rt->state & state) == state))
		|| ((s == RT_UNSET) && ((rt->state & state) == 0))
		|| ((s != RT_UNSET) && (s != RT_SET)))
		return (0);
	pthread_mutex_lock(&(rt->global_lock));
	pthread_mutex_lock(&(rt->state_lock));
#ifdef RT_DEBUG

	if (rt->debug.flags & RT_DBGF_STATECHANGE)
		ft_printf("[DEBUG] State %s : %#06X\n",
			(s == RT_SET) ? "set" : "unset", state);
#endif

	if (s == RT_SET)
		rt->state |= state;
	else
		rt->state &= ~state;
	pthread_mutex_unlock(&(rt->state_lock));
	pthread_mutex_unlock(&(rt->global_lock));
	return (1);
}
