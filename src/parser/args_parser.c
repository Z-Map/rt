/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:52:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 16:25:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_parser.h"

static int		is_validfile(const char *name)
{
	(void)name;
	return (0);
}

static int		getfileargs(t_rt *rt, int ac, char **av, size_t len)
{
	const char	*nametab[16];
	size_t		i;

	i = 0;
	while ((i < 16) && ac--)
		if (is_validfile(av[ac]))
			nametab[i++] = ft_vsdup(av[ac]);
	if (ac > 0)
		getfileargs(rt, ac, av, i);
	else if (!(len + i))
		return (0);
	else
	{
		rt->scenes = (const char **)malloc(sizeof(void *) * (len + i + 1));
		rt->scenes[len + i] = NULL;
		rt->scene_len = len + i;
	}
	while (i--)
		rt->scenes[len + i] = nametab[i];
	return (1);
}

int				rt_parse_args(t_rt *rt, int ac, char **av)
{
	t_arg		*arglst;
	t_argret	*argret;

	arglst = NULL;
	ft_setarg(&arglst, 'd', "command", &arg_commandmode);
	ft_setarg(&arglst, 'f', "fileout", &arg_fileout);
	ft_setarg(&arglst, 'c', "client", &arg_clientmode);
	ft_setarg(&arglst, 'v', "visual", &arg_visualprev);
	ft_setarg(&arglst, 'm', "modes", &arg_modes);
	argret = ft_parsearg(arglst, ac, av, rt);
	RT_DBGR(argret->argp, 0, "Arg parsed");
	ac = argret->ac;
	av = argret->av;
	if (ac)
	{
		getfileargs(rt, ac, av, 0);
		rt->scene = av[0];
	}
	ft_freearg(&arglst, argret);
	if (!(rt->flags & RT_MODES))
		rt->flags |= RT_VISUALPREV;
	return (1);
}
