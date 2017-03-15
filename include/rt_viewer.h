/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_viewer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:44:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/15 19:56:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_VIEWER_H
# define RT_VIEWER_H

# include "rt_prototype.h"
# include "rt_core.h"

void			*rt_viewer_main(void *arg);
int				rt_init_window(t_rt *rt);

int				viewer_presskcb(void *arg, int key);
int				viewer_releasekcb(void *arg, int key);
int				viewer_run(t_rt *rt, t_rtview *v);
int				viewer_loop(t_rt *rt);
void			*viewer_exit(t_rt *rt, int code);

#endif
