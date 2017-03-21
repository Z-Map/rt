/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_objects.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:56:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/21 19:04:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_OBJECTS
#define RT_DATA_OBJECTS

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

struct					s_rtcamera
{
	t_v2d				fov;
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
};

struct					s_rtmesh
{
	t_rtmat				*material;
	size_t				vertex_len;
	size_t				poly_len;
	t_v3f				*vertex;
	t_v3f				*normale;
	t_v2f				*uv;
	t_mat3ui			poly;
};

struct					s_rtlight
{
	float				intensity;
};

union					u_rt_objectdata
{
	struct s_rtcamera	camera;
	struct s_rtplan		plan;
	struct s_rtsphere	sphere;
	struct s_rtcone		cone;
	struct s_rtcylinder	cylinder;
	struct s_rtcuboid	cuboid;
	struct s_rtmesh		mesh;
	struct s_rtlight	light;
};

struct				s_rt_object_instance
{
	unsigned int	id;
	int				flags;
	char			*name;
	t_mattf			transform;
	t_rtobj			*obdata;
};

struct				s_rt_object
{
	t_rtobt			type:32;
	unsigned int	flags;
	char			*name;

};

#endif
