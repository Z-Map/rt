/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:41:54 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/31 18:23:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

static void		*rdr_workermain(t_rdrwrk *wrk)
{
	RT_DBGMC(RT_DBGM_WORKER|RT_DBGM_RENDER,"Render worker started.");
	wrk->ret = render_worker(wrk->start, wrk->step, wrk->rt, wrk->rmgr);
	pthread_exit(NULL);
}

int				rdr_start_workers(t_rt *rt, t_rtrmgr *mgr)
{
	t_rdrwrk	args[RDR_MAXWORKER];
	pthread_t	th[RDR_MAXWORKER];
	size_t		i;
	int			ret;

	RT_DBGMC(RT_DBGM_WORKER|RT_DBGM_RENDER, "Render workers creation.");
	ret = RTRMGR_FINISHED;
	i = RDR_MAXWORKER;
	while (i--)
	{
		args[i] = (t_rdrwrk){.rmgr = mgr, .rt = rt, .start = i,
			.step = RDR_MAXWORKER, .ret = RTRMK_ERROR};
		if (pthread_create(&(th[i]), NULL, (void *(*)(void *))&rdr_workermain,
			args + i))
			args[i].step = 0;
	}
	i = RDR_MAXWORKER;
	while (i--)
	{
		if (args[i].step)
			pthread_join(th[i], NULL);
		if (args[i].ret != RTRMGR_FINISHED)
			ret = args[i].ret;
	}
	return (ret);
}
