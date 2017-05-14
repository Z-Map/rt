/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:06:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/04 12:30:25 by qloubier         ###   ########.fr       */
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
	pthread_mutex_lock(&(rt->state_lock));
	if (s == RT_SET)
		rt->state |= state;
	else
		rt->state &= ~state;
	pthread_mutex_unlock(&(rt->state_lock));
	return (0);
}
