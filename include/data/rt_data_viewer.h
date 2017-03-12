/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_viewer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:07:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 15:16:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_VIEWER_H
# define RT_DATA_VIEWER_H

# include <pthread.h>
# include "rt_prototype.h"

struct					s_rt_viewer
{
	pthread_t			mainthread;
	mglwin				*win;
	mglwin				**wins;
	mglimg				*layer;
};

#endif
