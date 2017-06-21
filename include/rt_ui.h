/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:14:10 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 16:29:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UI_H
# define RT_UI_H

# include "data/data_ui.h"

/*
** singleton for unique id
*/
int					get_id_ui_node(void);

/*
** main init interface
*/
t_rtnode			*init_ui(t_v2i dim);

/*
** create root structure, node of type init
*/

t_layer_root		*mklayer_root(t_v2i dim);

/*
** create rectangle with param
*/
t_layer_rect		*mklayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

/*
** create node of rectangle with param
*/
t_rtnode			*mknlayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

/*
** update
*/
void				update_ui(t_rtnode *tree);

/*
** update dim of the first node (root)
*/
void				update_ui_root_dim(t_rt *rt);

/*
** found id othe the node
*/
t_rtnode			*tree_found_node_with_id(t_rtnode *node, int id);

/*
** add child with id node
*/
int					tree_addchild_wid(t_rtnode *tree, t_rtnode *node, int id);

#endif
