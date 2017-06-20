/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:14:10 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 20:14:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UI_H
# define RT_UI_H

# include "data/data_ui.h"

int				get_id_ui_node(void);

t_rtnode		*init_ui(t_v2i dim);

t_layer_root	*mklayer_root(t_v2i dim);

t_layer_rect	*mklayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

t_rtnode		*mknlayer_rect(t_v2f pos, t_v2f dim,\
		t_v4i color, int placement);

void		update_ui(t_rtnode *tree);

t_rtnode	*tree_found_node_with_id(t_rtnode *node, int id);

int		tree_addchild_wid(t_rtnode *tree, t_rtnode *node, int id);



#endif
