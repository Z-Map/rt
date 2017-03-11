/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:52:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/11 19:05:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int			rt_parse_args(t_rt *rt, int ac, char **av)
{
	if (ac > 1)
		rt->scene = av[1];
	else
		rt->scene = "data/scenes/default.sda";
	rt->flags |= RT_VISUALPREV;
	return (1);
}
