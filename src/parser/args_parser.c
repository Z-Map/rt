/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:52:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 01:38:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_parser.h"

int				rt_parse_args(t_rt *rt, int ac, char **av)
{
	if (ac)
		rt->scene = av[0];
	if (!(rt->flags & RT_MODES))
		rt->flags |= RT_VISUALPREV;
	return (1);
}
