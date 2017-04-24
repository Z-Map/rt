/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:52:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/24 15:39:44 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int			rt_parse_args(t_rt *rt, int ac, char **av)
{
//	t_arg	*arglst;

//	ft_setarg(&arglst, 'd', "command", &arg_commandmode);
//	ft_setarg(&arglst, 'f', "fileout", &arg_fileout);
//	ft_setarg(&arglst, 'c', "client", &arg_clientmode);
//	ft_setarg(&arglst, 'v', "visual", &arg_visualprev);
//	ft_setarg(&arglst, 'm', "modes", &arg_modes);
	if (ac > 1)
		rt->scene = av[1];
	else
		rt->scene = "data/scenes/default.sda";
	rt->flags |= RT_VISUALPREV;
	return (1);
}
