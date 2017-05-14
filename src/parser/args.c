/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:42:15 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/14 20:56:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			arg_commandmode(const char *arg, void *env,
		const char **nextargtab, int tab_len)
{
	t_rt	*rt;

	arg = NULL; // A ENLEVER
	nextargtab = NULL; // A ENLEVER
	tab_len = 0; // A ENLEVER
	rt = (t_rt *)env;
	rt->flags |= RT_COMMANDMODE;
	rt->flags &= ~RT_CLIENTMODE;
	return (0);
}

int			arg_fileout(const char *arg, void *env,
		const char **nextargtab, int tab_len)
{
	t_rt	*rt;

	arg = NULL; // A ENLEVER
	rt = (t_rt *)env;
	if (tab_len)
		rt->fileout = ft_strdup(nextargtab[0]);
	else
		return (0);
	return (1);
}

int			arg_clientmode(const char *arg, void *env,
		const char **nextargtab, int tab_len)
{
	t_rt	*rt;

	arg = NULL; // A ENLEVER
	nextargtab = NULL; // A ENLEVER
	tab_len = 0; // A ENLEVER
	rt = (t_rt *)env;
	rt->flags = (rt->flags & ~RT_MODES) | RT_CLIENTMODE;
	return (0);
}

int			arg_visualprev(const char *arg, void *env,
		const char **nextargtab, int tab_len)
{
	t_rt	*rt;

	arg = NULL; // A ENLEVER
	nextargtab = NULL; // A ENLEVER
	tab_len = 0; // A ENLEVER
	rt = (t_rt *)env;
	rt->flags |= RT_VISUALPREV | ~RT_CLIENTMODE;
	return (0);
}

int			arg_modes(const char *arg, void *env,
		const char **nextargtab, int tab_len)
{
	t_rt	*rt;

	arg = NULL; // A ENLEVER
	nextargtab = NULL; // A ENLEVER
	tab_len = 0; // A ENLEVER
	rt = (t_rt *)env;
	rt->flags |= RT_MODES;
	return (0);
}
