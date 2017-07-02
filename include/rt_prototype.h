/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:31:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:20:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPE_H
# define RT_PROTOTYPE_H

# include "libft.h"

# include "generated/rt_proto_gen.h"

# define RT_DEFAULT_RSIZE_X			512
# define RT_DEFAULT_RSIZE_Y			512

/*
** RT Tool
*/

# define RT_GET						2
# define RT_SET						1
# define RT_LEN						4
# define RT_UNSET					0

/*
** RT Flags
*/

# define RT_COMMANDMODE				0x1ul
# define RT_FILEOUT					0x2ul
# define RT_CLIENTMODE				0x4ul
# define RT_VISUALPREV				0x8ul
# define RT_MODES					0xFul

# define RTF_RDRDISP				0x1000ul
# define RTF_RDRAUTO				0x2000ul
# define RTF_RDRREFRESH				0x4000ul
# define RTF_CLEARLAYER				0x8000ul
# define RTF_FILTER					0x10000ul

# define RTR_CG						0x100ul

/*
** RT States
*/

# define RTS_INIT					0x1ul
# define RTS_MGLW_INIT				0x2ul
# define RTS_RDRMGR_INIT			0x4ul
# define RTS_SLEEP					0x8ul
# define RTS_QUIT					0x10ul
# define RTS_RENDER					0x20ul
# define RTS_VPREV					0x40ul

/*
** Render Manager
*/

# define RTRMGR_STARTRENDER			2048
# define RTRMGR_FINISHED			256
# define RTRMGR_REFRESH				0x1ul

# define RTRMK_REFRESH				0x1ul
# define RTRMK_STOP					0x2ul
# define RTRMK_CANCEL				0x4ul
# define RTRMK_DONE					0x10ul
# define RTRMK_ERROR				0x20ul

/*
** Ray flags
*/

# define RAY_GDEPTH					0x1ul
# define RAY_GHPOINT				0x10ul
# define RAY_GHTANG					0x20ul
# define RAY_GHNOR					0x40ul
# define RAY_GLOCAL					0x100ul
# define RAY_GINTER					0x200ul
# define RAY_GINFO					0x371ul
# define RAY_GVALID					0x1000ul

/*
** Objects flags
*/

# define LIGTH_MAKESHADOW			0x100ul
# define LIGTH_GLOW					0x200ul
# define LIGTH_DIFFUSE				0x400ul
# define LIGTH_NEGATIVE				0x800ul

/*
** Objects flags
*/

# define TEX_VALID					0x1u
# define TEX_LOADED					0x2u
# define TEX_PROCEDURALE			0x4u

/*
** Window key
*/

# define RTWK_REFRESH				0x1ul
# define RTWK_STOP					0x2ul

/*
** Tree
*/

# define TREET_TREE					0x1u
# define TREET_NODE					0x2u
# define TREET_RENDER				0x10u
# define RTNF_RTREE					0x11u
# define RTNF_RNODE					0x12u

/*
** Debug
*/

# define RT_DBGF_ALLCP				0x1ul
# define RT_DBGF_DISPKEY			0x2ul
# define RT_DBGF_STATECHANGE		0x4ul
# define RT_DBGF_MSG				0x8ul
# define RT_DBGF_INFO				0x10ul
# define RT_DBGF_RET				0x20ul
# define RT_DBGF_ALLRET				0x40ul
# define RT_DBGF_RETCP				0x80ul

# define RT_DBGM_GLOBALE			0x1ul
# define RT_DBGM_RENDER				0x2ul
# define RT_DBGM_WORKER				0x4ul
# define RT_DBGM_PARSER				0x8ul

typedef struct s_rt_root				t_rt;
typedef struct s_rt_viewer				t_rtview;
typedef struct s_rt_render				t_rtr;

typedef struct s_rt_tree				t_rtree;
typedef struct s_rt_rdr_rtree			t_rdrtree;
typedef struct s_rt_treenode			t_rtnode;
typedef struct s_rt_rtreenode			t_rtrnode;
typedef struct s_rt_object_instance		t_rtobi;
typedef struct s_rt_object_index		t_rtobind;
typedef struct s_rt_object				t_rtobj;
typedef struct s_rt_material			t_rtmat;
typedef struct s_rt_texture				t_rtex;
typedef struct s_rt_texinstance			t_rtexi;
typedef union u_rt_objectdata			t_rtobd;

/*
** typedef enum						e_rt_object_type
** {
**	INVALID		= 0,
**	SCENE		= 0x1,
**	EMPTY		= 0x2,
**	CAMERA		= 0x4,
**	PLAN		= 0x8,
**	SPHERE		= 0x10,
**	CONE		= 0x20,
**	CYLINDER	= 0x40,
**	CUBOID		= 0x80,
**	TRIS		= 0x100,
**	MESH		= 0x200,
**	SPOT		= 0x400,
**	POINTLIGHT	= 0x800,
**	SUNLIGHT	= 0x1000,
**	NOTYPE		= 0x2000,
**	VISIBLE		= PLAN | SPHERE | CONE | CYLINDER | CUBOID | TRIS | MESH,
**	LIGHT		= SPOT | POINTLIGHT | SUNLIGHT,
**	TOOL		= EMPTY | CAMERA,
**	VALID		= VISIBLE | LIGHT | TOOL | SCENE
** }									t_rtobt;
*/

typedef struct s_rt_render_ray			t_rtray;
typedef struct s_rt_render_gdata		t_rtrgd;
typedef struct s_rt_fastrdr_gdata		t_rtfrgd;
typedef struct s_rt_light_data			t_rtrld;
typedef struct s_rt_render_fdata		t_rtrfd;
typedef struct s_rt_render_data			t_rtrd;

typedef struct s_obj					t_obj;

/*
** layer
*/
typedef struct s_layer_generic			t_layer_gen;

typedef struct s_layer_root				t_layer_root;
typedef struct s_layer_rect				t_layer_rect;
typedef struct s_layer_border			t_layer_border;
typedef struct s_layer_checkbox			t_layer_checkbox;
typedef struct s_layer_loadbar			t_layer_loadbar;
typedef struct s_layer_variator			t_layer_variator;
typedef struct s_layer_term				t_layer_term;
typedef struct s_layer_label			t_layer_label;

typedef struct s_term					t_term;

#endif
