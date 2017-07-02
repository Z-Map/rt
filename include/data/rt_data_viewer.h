/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_viewer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:07:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 13:29:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_VIEWER_H
# define RT_DATA_VIEWER_H

# include <pthread.h>
# include "mglw/mglw.h"
# include "mathex/vector.h"

# include "rt_prototype.h"

struct					s_rt_viewer
{
	pthread_t			mainthread;
	pthread_mutex_t		refresh_lock;
	pthread_cond_t		refresh_cond;
	unsigned long		keys;
	t_v2f				mouse;
	mglwin				*win;
	mglwin				**wins;
	mglimg				*layer;
	mglimg				*rdrtarget;
	mglca				*font;
	t_rtnode			*ui;
	t_rtnode			*layer_event_focus;
	t_rtnode			*layer_main_loadbar;
};

#endif
