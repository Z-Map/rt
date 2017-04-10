/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:45:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/10 16:07:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TREE_H
# define RT_TREE_H

#include <stdarg.h>

# include "rt_prototype.h"
# include "data/rt_data_core.h"
# include "data/rt_data_objects.h"
# include "data/rt_data_tree.h"

t_rtnode			*mknode(t_rtobi *ob_inst); // <<
t_rtree				*mktree(size_t num, ...);
int					rmnode(t_rtnode *node); // <<
int					rmnodes(size_t num, ...);
int					rmrnode(t_rtnode *node);
int					rmrnodes(size_t num, ...);
int					rmtree(t_rtree *tree);
// Add child "node" to "parent" - return node or null if error
t_rtnode			*tree_addchild(t_rtnode *parent, t_rtnode *node); // <<
// Remove child "node" from "parent" - return node or null if error
t_rtnode			*tree_delchild(t_rtnode *parent, t_rtnode *node); // <<
// Add all childs of "node" as "parent" child and remove node - return node or null if error
t_rtnode			*tree_collapsechild(t_rtnode *parent, t_rtnode *node);

// Set "parent" as parent of node and remove "node" from his parent before
// if needed - return node or null if error
t_rtnode			*tree_setparent(t_rtnode *node, t_rtnode *parent);

#endif
