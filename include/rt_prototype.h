/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:31:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/19 14:38:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPE
# define RT_PROTOTYPE

# include "libft.h"

typedef struct s_rt_root			t_rt;
typedef struct s_rt_viewer			t_rtview;

typedef struct s_rt_tree			t_rtree;
typedef struct s_rt_treenode		t_rtnode;
typedef struct s_rt_object_instance	t_rtobi;
typedef struct s_rt_object			t_rtobj;

typedef enum						e_rt_object_type
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
	SETTING = 1 << 13,
	CONE_INF = 1 << 14,
	NOSHADER = 1 << 28,
	TRIANGLE = 1 << 29,
	MESH = 1 << 30,
	RADIUS = SPHERE | CUBE | CYL | CONE | CONE_INF,
	VISIBLE = CUBE | PLAN | SPHERE | FACE | CONE | CYL | CONE_INF |
	TRIANGLE | MESH,
	NOCHECKBOX = PLAN | CYL | CONE_INF,
	BOUNDED = CUBE | SPHERE | FACE | CONE | CYL | CONE_INF | TRIANGLE |
	EMPTY,
	LIGHTTYPE = SPOT | POINTLIGHT | SUNLIGHT,
}									t_rtobt;



typedef struct s_obj				t_obj;


# define RT_COMMANDMODE				0x1
# define RT_FILEOUT					0x2
# define RT_CLIENTMODE				0x4
# define RT_VISUALPREV				0x8
# define RT_MODES					0xF

# define RTS_INIT					0x1
# define RTS_MGLW_INIT				0x2
# define RTS_RENDER					0x4
# define RTS_SLEEP					0x8
# define RTS_QUIT					0x10
# define RTS_VPREV					0x20

# define RTWK_REFRESH				0x1
# define RTWK_STOP					0x2

#endif
