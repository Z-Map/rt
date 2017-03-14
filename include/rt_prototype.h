/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:31:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/14 19:57:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPE
# define RT_PROTOTYPE

# include "libft.h"
# include "mathex/vector.h"
# include "mglw/mglw.h"

typedef struct s_rt_root			t_rt;
typedef struct s_rt_viewer			t_rtview;
typedef struct s_rt_tree			t_rtree;

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
