/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ui_root_dim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:57:07 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 22:57:20 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"
#include "rt_prototype.h"
#include "rt_tree.h"

void				update_ui_root_dim(t_rt *rt)
{
	t_layer_root	*root;

	root = (t_layer_root *)(rt->viewer.ui->content);
	root->gen.dim.x = rt->viewer.layer->x;
	root->gen.dim.y = rt->viewer.layer->y;
}
