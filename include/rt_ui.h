/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:14:10 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:31:36 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UI_H
# define RT_UI_H

# include "data/data_ui.h"

/*
** singleton for unique id
*/
int							get_id_ui_node(void);

/*
** main init interface
*/
t_rtnode					*init_ui(t_v2i dim);

/*
** create root structure, node of type init
*/

t_layer_root				*mklayer_root(t_v2i dim);

/*
** create rectangle with param
*/
t_layer_rect				*mklayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

/*
** create node of rectangle with param
*/
t_rtnode					*mknlayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

t_layer_border				*mklayer_border(t_v2f pos, t_v2f dim, t_v4i color,\
int placement);

t_rtnode					*mknlayer_border(t_v2f pos, t_v2f dim,\
t_v4i color, int placement);

t_layer_checkbox			*mklayer_checkbox(t_v2f pos, t_v2f dim,\
t_v4i color, int placement);

t_rtnode					*mknlayer_checkbox(t_v2f pos, t_v2f dim,\
t_v4i color, int placement);

t_layer_loadbar	*mklayer_loadbar(t_v2f pos, t_v2f dim, t_v4i color[2],\
	int placement);

t_rtnode	*mknlayer_loadbar(t_v2f pos, t_v2f dim, t_v4i color[2],\
        int placement);

t_layer_variator		*mklayer_variator(t_v2f pos, t_v2f dim, t_v4i color[2], int placement);
t_rtnode		*mknlayer_variator(t_v2f pos, t_v2f dim, t_v4i color[2], int placement);

void            mklayer_main_term(t_layer_term *term, int size);

t_rtnode        *mknlayer_term(t_v2f pos, t_v2f dim, t_v4i color,\
int placement);

t_layer_label   *mklayer_label(t_v2f pos, t_v2f dim, t_v4i color,\
int placement);

void            layer_label_add(t_layer_label *label, char *str);

t_rtnode        *mknlayer_label(t_v2f pos, t_v2f dim, t_v4i color,\
	int placement);

void						event_click_checkbox(t_layer_checkbox *cb);

void						event_click_variator(t_rt *rt, t_rtnode *node);

void						event_noclick_variator(t_rt *rt);

void						event_onclick_variator(t_rt *rt);

void						event_ui(t_rt *rt);

/*
** update
*/
void						update_ui(t_rtnode *tree);

void						update_loadbar(t_layer_loadbar *load, t_layer_gen *gen_father);

void						update_variator(t_layer_variator *var, t_layer_gen *gen_father);

void						update_pos(t_layer_gen *father, t_layer_gen *stock,\
						t_v2f pos, t_v2f dim);

/*
** update dim of the first node (root)
*/
void						update_ui_root_dim(t_rt *rt);

/*
** found id othe the node
*/
t_rtnode					*tree_found_node_with_id(t_rtnode *node, int id);

/*
** add child with id node
*/
int							tree_addchild_wid(t_rtnode *tree,\
		t_rtnode *node, int id);

/*
** manage of the position : postion relative
*/
void						center_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c);
void						top_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c);
void						bottom_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c);
void						left_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c);
void						right_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c);
void						main_pts_placement(int placement, t_v2i *pos,\
		t_v2i dim_p, t_v2i dim_c);

/*
** savoir si une position est comprise dans un element node
*/

int							ui_check_hit(t_rtnode *node, t_v2i *pos_cursor);

int							ui_is_event(t_layer_gen gen);

/*
** trouver  evenement element associe a l aposition de la souris
** eviter les evenement superpose sinon risque de bug
*/
void						ui_found_elem_with_pos(t_rtnode *node,\
		t_rtnode **found, t_v2i *pos_cursor);

void		delui(t_rtnode *node);

#endif
