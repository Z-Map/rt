/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:31:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/27 18:29:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPE
# define RT_PROTOTYPE

# include "libft.h"

typedef struct s_rt_root			t_rt;
typedef struct s_rt_viewer			t_rtview;
typedef struct s_rt_render			t_rtr;

typedef enum						e_valuetype
{
	PT_INT,
	PT_LONG,
	PT_FLOAT,
	PT_DOUBLE,
	PT_COLOR,
	PT_VEC2I,
	PT_VEC3I,
	PT_VEC4I,
	PT_VEC2L,
	PT_VEC3L,
	PT_VEC4L,
	PT_VEC2F,
	PT_VEC3F,
	PT_VEC4F,
	PT_VEC2D,
	PT_VEC3D,
	PT_VEC4D,
	PT_STR,
	PT_OBJECT
}									t_vt;

typedef struct s_rt_tree			t_rtree;
typedef struct s_rt_treenode		t_rtnode;
typedef struct s_rt_object_instance	t_rtobi;
typedef struct s_rt_object			t_rtobj;
typedef struct s_rt_material		t_rtmat;
typedef union u_rt_objectdata		t_rtobd;

typedef enum						e_rt_object_type
{
	INVALID		= 0,
	SCENE		= 0x1,
	EMPTY		= 0x2,
	CAMERA		= 0x4,
	PLAN		= 0x8,
	SPHERE		= 0x10,
	CONE		= 0x20,
	CYLINDER	= 0x40,
	CUBOID		= 0x80,
	TRIS		= 0x100,
	MESH		= 0x200,
	SPOT		= 0x400,
	POINTLIGHT	= 0x800,
	SUNLIGHT	= 0x1000,
	NOTYPE		= 0x2000,
	VISIBLE		= PLAN | SPHERE | CONE | CYLINDER | CUBOID | TRIS | MESH,
	LIGHT		= SPOT | POINTLIGHT | SUNLIGHT,
	TOOL		= EMPTY | CAMERA,
	VALID		= VISIBLE | LIGHT | TOOL | SCENE
}									t_rtobt;

typedef struct s_rt_render_ray		t_rtray;
typedef struct s_rt_render_gdata	t_rtrgd;
typedef struct s_rt_render_fdata	t_rtrfd;
typedef struct s_rt_render_data		t_rtrd;

typedef struct s_obj				t_obj;


# define RT_COMMANDMODE				0x1ul
# define RT_FILEOUT					0x2ul
# define RT_CLIENTMODE				0x4ul
# define RT_VISUALPREV				0x8ul
# define RT_MODES					0xFul

# define RTS_INIT					0x1ul
# define RTS_MGLW_INIT				0x2ul
# define RTS_RENDER					0x4ul
# define RTS_SLEEP					0x8ul
# define RTS_QUIT					0x10ul
# define RTS_VPREV					0x20ul

# define RTR_CG						0x1ul

# define RTWK_REFRESH				0x1ul
# define RTWK_STOP					0x2ul

#endif
