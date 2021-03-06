/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_viewer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:44:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 11:46:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_VIEWER_H
# define RT_VIEWER_H

# include <pthread.h>
# include "mglw/mglw.h"

# include "rt_prototype.h"
# include "rt_core.h"
# include "rt_ui.h"
# include "rt_ui_display.h"

void			*rt_viewer_main(void *arg);
int				rt_init_window(t_rt *rt);

int				viewer_presskcb(void *arg, int key);
int				viewer_releasekcb(void *arg, int key);
int				viewer_run(t_rt *rt, t_rtview *v);
int				viewer_loop(t_rt *rt);
void			*viewer_exit(t_rt *rt, int code);

void			viewer_clearlayer(t_rt *rt);

#endif
