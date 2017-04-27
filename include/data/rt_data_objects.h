/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_objects.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:56:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/27 16:49:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_OBJECTS
#define RT_DATA_OBJECTS

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

struct					s_rtscene
{
	t_rtmat				*ambient_light;
	t_rtmat				*skybox;
};

struct					s_rtempty
{
	void				*subtree;
	float				size;
};

struct					s_rtcamera
{
	t_v2d				fov;
	float				focus;
};

struct					s_rtplan
{
	t_rtmat				*material;
};

struct					s_rtsphere
{
	t_rtmat				*material;
	float				radius;
};

struct					s_rtcone
{
	t_rtmat				*material;
	float				angle;
};

struct					s_rtcylinder
{
	t_rtmat				*material;
	float				radius;
};

struct					s_rtcuboid
{
	t_rtmat				*material;
	float				radius;
};

struct					s_rtmesh
{
	t_rtmat				*material;
	size_t				vertex_len;
	size_t				poly_len;
	t_v3f				*vertex;
	t_v3f				*normale;
	t_v2f				*uv;
	t_v3ui				*poly;
};

struct					s_rtlight
{
	t_rtmat				*material;
	float				radius;
	float				angle;
	float				intensity;
};

t_val					g_rtlight[] = {
	(t_val){"material", PT_MAT},
	(t_val){"radius", PT_FLOAT},
	(t_val){"angle", PT_FLOAT},
	(t_val){"intensity", PT_FLOAT}
};

union					u_rt_objectdata
{
	struct s_rtscene	scene;
	struct s_rtempty	empty;
	struct s_rtcamera	camera;
	struct s_rtplan		plan;
	struct s_rtsphere	sphere;
	struct s_rtcone		cone;
	struct s_rtcylinder	cylinder;
	struct s_rtcuboid	cuboid;
	struct s_rtmesh		mesh;
	struct s_rtlight	light;
};

struct					s_rt_object_instance
{
	unsigned int		id;
	int					flags;
	char				*name;
	t_mattf				transform;
	t_rtobj				*obdata;
};

struct					s_rt_object
{
	t_rtobt				type:32;
	t_rgba				color;
	unsigned long		flags;
	unsigned long		usercfg;
	size_t				instances;
	char				*name;
	t_rtobd				data;
};

#endif
