/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:52:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 21:54:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int				rt_parse_args(t_rt *rt, int ac, char **av)
{
	t_arg		*arglst;
	t_argret	*argret;

	ft_setarg(&arglst, 'd', "command", &arg_commandmode);
	ft_setarg(&arglst, 'f', "fileout", &arg_fileout);
	ft_setarg(&arglst, 'c', "client", &arg_clientmode);
	ft_setarg(&arglst, 'v', "visual", &arg_visualprev);
	ft_setarg(&arglst, 'm', "modes", &arg_modes);
	argret = ft_parsearg(arglst, ac, av, rt);
	RT_DBGR(argret->argp, 0, "Arg parsed");
	ac = argret->ac;
	av = argret->av;
	ft_freearg(&arglst, argret);
	if (ac)
		rt->scene = av[0];
	if (!(rt->flags & RT_MODES))
		rt->flags |= RT_VISUALPREV;
	return (1);
}
