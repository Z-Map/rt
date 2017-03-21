/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:31:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/21 17:14:23 by qloubier         ###   ########.fr       */
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
typedef struct s_rt_material		t_rtmat;
typedef union u_rt_objectdata		t_rtobd;

typedef enum						e_rt_object_type
{
	INVALID		 = 0,
	ROOT		 = 0x1,
	EMPTY		 = 0x2,
	CAMERA		 = 0x4,
	PLAN		 = 0x8,
	SPHERE		 = 0x10,
	CONE		 = 0x20,
	CYLINDER	 = 0x40,
	CUBOID		 = 0x80,
	TRIS		 = 0x100,
	MESH		 = 0x200,
	SPOT		 = 0x400,
	POINTLIGHT	 = 0x800,
	SUNLIGHT	 = 0x1000,
	VISIBLE		 = PLAN | SPHERE | CONE | CYLINDER | CUBE | TRIS | MESH,
	LIGHT		 = SPOT | POINTLIGHT | SUNLIGHT,
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
