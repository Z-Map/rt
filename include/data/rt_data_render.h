/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_render.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:03:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 07:10:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_RENDER_H
# define RT_DATA_RENDER_H

# include <pthread.h>
# include "mathex/vector.h"
# include "mathex/matrix.h"

# include "rt_prototype.h"

struct					s_rt_render_ray
{
	t_v3f				start;
	t_v3f				direction;
	t_rgba				color;
	int					intensity;
};

struct					s_rt_render_gdata
{
	t_rgba				color;
	t_ui				flags;
	double				depth;
	t_v3f				hit_point;
	t_v3f				hit_nor;
	t_mat2x3f			hit_tangent;
};

struct					s_rt_render_fdata
{
	t_rgba				color;
	t_ui				flags;
	double				depth;

};

struct					s_rt_render_data
{
	t_rgba				color;
	t_ui				flags;
	double				depth;
};

typedef struct			s_rt_render_manager
{
	unsigned long		rdrstate;
	t_v2ui				rsize;
	t_rgba				*rpx;
	t_rtree				*rendertree;
}						t_rtrmgr;

struct					s_rt_render
{
	pthread_t			mgrthread;
	pthread_mutex_t		refresh_lock;
	pthread_cond_t		refresh_cond;
	t_ul				flags;
	t_rtree				*target;
	t_v2ui				render_size;
	t_rgba				*render_px;
};

#endif
