/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:47:00 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/26 15:57:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# include <pthread.h>

# include "rt_prototype.h"
# include "rt_core.h"

# include "data/rt_data_render.h"

void		*rt_rdrmgr_main(void *arg);
int			rdrmgr_isalive(t_rt *rt);
int			rdrmgr_sync(t_rt *rt);
void		*rdrmgr_exit(t_rt *rt, int code);

#endif
