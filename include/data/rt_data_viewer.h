/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_viewer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:07:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/21 18:42:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_VIEWER_H
# define RT_DATA_VIEWER_H

# include <pthread.h>
# include "mglw/mglw.h"

# include "rt_prototype.h"

struct					s_rt_viewer
{
	pthread_t			mainthread;
	pthread_mutex_t		refresh_lock;
	pthread_cond_t		refresh_cond;
	unsigned long		keys;
	mglwin				*win;
	mglwin				**wins;
	mglimg				*layer;
	mglimg				*rdrtarget;
	t_rtnode			*ui;
};

#endif
