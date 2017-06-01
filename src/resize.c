/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:54:32 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/01 01:58:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"

void		rt_resize(void *env, int x, int y)
{
	t_rt	*rt;

	if (!env)
		return ;
	rt = (t_rt *)env;
	
	rt->render.target_size = (t_v2ui){x, y};
	rt->flags |= RTF_RDRREFRESH;
}
