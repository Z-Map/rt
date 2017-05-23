/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:45:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/23 03:45:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TREE_H
# define RT_TREE_H

# include <stdarg.h>

# include "rt_prototype.h"
# include "data/rt_data_core.h"
# include "data/rt_data_objects.h"
# include "data/rt_data_tree.h"

# define FAILURE	-1
# define INFIX 		1
# define PREFIX		2
# define SUFFIX		4

t_rtnode			*mknode(t_rtobi *ob_inst); // <<
t_rtree				*mktree(size_t num, ...);
int					rmnode(t_rtnode **node); // <<
int					rmnodes(size_t num, ...);
int					rmrnode(t_rtnode **node);
int					rmrnodes(size_t num, ...);
int					rmtree(t_rtree **tree);
// Add child "node" to "parent" - return node or null if error
t_rtnode			*tree_addchild(t_rtnode *parent, t_rtnode *node); // <<
// Remove child "node" from "parent" - return node or null if error
t_rtnode			*tree_delchild(t_rtnode *parent, t_rtnode *node); // <<
// Add all childs of "node" as "parent" child and remove node
// - return node or null if error
t_rtnode			*tree_collapsechild(t_rtnode *parent, t_rtnode *node);
t_rtnode			*tree_childup(t_rtnode *childs);
t_rtnode			*tree_nodedup(t_rtnode *node);
t_rtree				*tree_dup(t_rtree *tree);

// TO DO :
//*
// Update stats of tree
void				tree_stats(t_rtree *tree);
// Search node with this content
t_rtnode			*tree_chr(t_rtree *tree, void *content);
// Search throught a tree for node with content that valid f(node.content)
// The search can be continued if the node last find node is passed to "node"
t_rtnode			*tree_find(t_rtnode *node, int (*f)(void *));
//*/

// Set "parent" as parent of node and remove "node" from his parent before
// if needed - return node or null if error
t_rtnode			*tree_setparent(t_rtnode *node, t_rtnode *parent);
int					tree_foreach(t_rtnode *node, int method,
						int (*f)(t_rtnode *, void *), void *env);

int					print_tree(t_rtree *tree);

t_rtrnode			*rendernodedup(t_rtnode *node, t_mattf m, t_mat3x2f *b);
t_rtrnode			*mkrendernode(t_rtobi *inst, t_mattf mtrx, t_mat3x2f lb);
t_rtree				*mkrendertree(t_rtree *tree);

#endif
