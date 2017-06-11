/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_render.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:03:08 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 23:03:28 by qloubier         ###   ########.fr       */
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
	t_ul				flags;
	t_v2f				depth;
	t_v4f				hit_point;
	t_mat2x3f			hit_tangent;
	t_v3f				hit_nor[2];
	t_rtray				ray;
	t_rtobi				*inst;
	t_rtrnode			*node;
};

struct					s_rt_fastrdr_gdata
{
	t_ul				flags;
	t_v2f				depth;
	t_v4f				hit_point;
};

struct					s_rt_light_data
{
	t_ul				flags;
	t_v3f				v;
	float				depth;
	t_v3f				color;
	float				pwr;
	t_rtrnode			*nod;
};

struct					s_rt_render_fdata
{
	t_v4f				color;
	t_v3f				hit_nor;
	float				ndepth;
};

struct					s_rt_render_data
{
	t_rtray				ray;
	t_rtray				lray;
	t_rtrgd				geo;
	t_rtrgd				lgeo;
	t_rtrfd				frag;
	t_rdrtree			*tree;
	float				fdepth;
	t_rgba				fcolor;
};

typedef struct			s_rt_render_manager
{
	unsigned long		rdrstate;
	t_v2ui				rsize;
	t_rgba				*rpx;
	t_rdrtree			*rendertree;
	t_rt				*rt;
}						t_rtrmgr;

typedef struct			s_worker_arg
{
	t_rtrmgr			*rmgr;
	t_rt				*rt;
	t_ui				start;
	t_ui				step;
	int					ret;
	int					padding;
}						t_rdrwrk;

struct					s_rt_render
{
	pthread_t			mgrthread;
	pthread_mutex_t		refresh_lock;
	pthread_cond_t		refresh_cond;
	t_ul				flags;
	t_v2ui				target_size;
	t_rtree				*target;
	t_v2ui				render_size;
	t_rgba				*render_px;
};

#endif
