/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:19:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 15:37:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_CORE_H
# define RT_DATA_CORE_H

# include <pthread.h>

# include "rt_prototype.h"
# include "data/rt_data_viewer.h"
# include "data/rt_data_render.h"

struct						s_debugger
{
	unsigned long			flags;
	unsigned long			mask;
	int						codepoint;
	int						cpline;
	const char				*cpname;
	const char				*cpfile;
	const char				*cpfunc;
};

struct						s_rt_root
{
	pthread_mutex_t			global_lock;
	unsigned long			flags;
	pthread_mutex_t			state_lock;
	unsigned long			state;
	int						error;
	int						errors[15];
	char					*scene;
	char					*fileout;
	t_rtview				viewer;
	t_rtr					render;
	struct s_debugger		debug;
};

#endif
