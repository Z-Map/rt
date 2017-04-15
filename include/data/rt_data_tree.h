/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:59:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/13 23:05:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_TREE_H
# define RT_DATA_TREE_H

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

struct				s_rt_treenode
{
	t_rtnode		*parent;
	t_rtnode		*next;
	t_rtnode		*childs;
	unsigned int	type;
	unsigned int	flags;
	t_rtobi			*instance;
};

struct				s_rt_tree
{
	t_rtnode		node;
	unsigned int	max_depth;
	unsigned int	nodelen;
	t_blst			*buffer;
};

struct				s_rt_rtreenode
{
	t_rtnode		node;
	t_mattf			transform;
	t_mattf			invert_transform;
};


#endif
