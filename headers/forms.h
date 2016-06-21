/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:01:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/21 18:10:07 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_H
# define FORMS_H
# include "draw.h"

typedef unsigned int	t_uint;
typedef t_point			t_v2i;
typedef t_m4			t_mattf;

typedef enum			e_type
{
	ROOT = 1,
	CUBE = 1 << 1,
	PLAN = 1 << 2,
	SPHERE = 1 << 3,
	CAMERA = 1 << 4,
	EMPTY = 1 << 5,
	SPOT = 1 << 6,
	POINTLIGHT = 1 << 7,
	FACE = 1 << 8,
	INVALID = 1 << 9,
	CONE = 1 << 10,
	CYL = 1 << 11,
	SUNLIGHT = 1 << 12,
	RADIUS = SPHERE | CUBE | CYL | CONE,
	VISIBLE = CUBE | PLAN | SPHERE | FACE | CONE | CYL,
	NOCHECKBOX = PLAN | CYL,
	BOUNDED = CUBE | SPHERE | FACE | CONE | CYL,
	LIGHTTYPE = SPOT | POINTLIGHT | SUNLIGHT,
	TEXTURE = CYL
}						t_type;

enum					e_stop
{
	OK = 0,
	STOP_NODE = 1,
	STOP_ALL = 1 << 1
};

typedef struct			s_typecmp
{
	t_type				type;
	const char			*str;
}						t_typecmp;

typedef struct			s_v2d
{
	double				x;
	double				y;
}						t_v2d;

typedef struct			s_typesize
{
	t_type				type;
	size_t				size;
}						t_typesize;

typedef struct			s_cube
{
	unsigned int		color;
	float				size;
}						t_cube;

typedef struct			s_plan
{
	unsigned int		color;
}						t_plan;

typedef struct			s_cone
{
	unsigned int		color;
	float				size;
	t_v4d				angle;
}						t_cone;

typedef struct			s_cyl
{
	unsigned int		color;
	float				radius;
	float				height;
}						t_cyl;

typedef struct			s_sphere
{
	unsigned int		color;
	float				radius;
}						t_sphere;

typedef struct			s_plight
{
	unsigned int		color;
	float				radius;
	double				intensity;
}						t_plight;

typedef struct			s_camera
{
	t_mattf				rtrans;
	t_v2d				steppx;
	t_v4d				rayfix;
	t_v4d				rayreset;
	t_v4d				raypos;
	t_v4d				mdirx;
	t_v4d				mdiry;
	t_v4d				origin_rot;
	t_m4				origin;
	double				fov;
	double				fovx;
}						t_camera;

typedef struct			s_ray
{
	t_v4d				start;
	t_v4d				dir;
	double				limit;
	double				lenght;
	unsigned int		color;
}						t_ray;

typedef struct			s_box
{
	float				xmin;
	float				xmax;
	float				ymin;
	float				ymax;
	float				zmin;
	float				zmax;
}						t_box;

#endif
