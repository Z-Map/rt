/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 23:05:29 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 07:25:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"

static const char	*print_info(t_rt *rt, const char *msg,
						int l, const char *file, const char *func)
{
	if (rt->debug.flags & RT_DBGF_INFO)
		ft_printf("[DEBUG] line %i in %s <function %s> : ", l, file, func);
	else
		ft_printf("[DEBUG] ");
	return (msg);
}

int					rtd_point(t_rt *rt, int code, const char *name,
						int l, const char *file, const char *func)
{
	pthread_mutex_lock(&(rt->global_lock));
	rt->debug.codepoint = code;
	rt->debug.cpline = l;
	rt->debug.cpname = name;
	rt->debug.cpfile = file;
	rt->debug.cpfunc = func;
	if (rt->debug.flags & RT_DBGF_ALLCP)
		ft_printf(print_info(rt, "Reached debug point %s with code %i.\n",
			l, file, func), name, code);
	pthread_mutex_unlock(&(rt->global_lock));
	return (code);
}

int					rtd_ret(t_rt *rt, int retcode, int code, const char *msg,
						int l, const char *file, const char *func)
{
	pthread_mutex_lock(&(rt->global_lock));
	if (rt->debug.flags & RT_DBGF_RET)
	{
		if (retcode != code)
			ft_printf(print_info(rt, "Return failed with code %i :\n%s\n",
				l, file, func), retcode, msg);
		else if (rt->debug.flags & RT_DBGF_ALLRET)
			ft_printf(print_info(rt, "Return succeed with code %i.\n",
				l, file, func), retcode);
		else
			return (retcode);
		if (rt->debug.cpname)
			return (retcode);
		ft_printf("Last debug point reach : %s with code %i",
			rt->debug.cpname, rt->debug.codepoint);
		ft_printf(" at line %i in %s <function %s>\n", rt->debug.cpline,
			rt->debug.cpfile, rt->debug.cpfunc);
	}
	pthread_mutex_unlock(&(rt->global_lock));
	return (retcode);
}

int					rtd_msg(t_rt *rt, unsigned long mask, const char *msg,
						int l, const char *file, const char *func)
{
	pthread_mutex_lock(&(rt->global_lock));
	if ((rt->debug.flags & RT_DBGF_MSG) && ((!mask) || (mask & rt->debug.mask)))
		ft_printf(print_info(rt, "%s\n", l, file, func), msg);
	pthread_mutex_unlock(&(rt->global_lock));
	return (0);
}
