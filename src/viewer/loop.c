/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:20:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/22 19:18:57 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"
#include "rt_prototype.h"
#include "data/rt_data_viewer.h"
#include "rt_ui_display.h"
#include "data/rt_data_tree.h"
#include <stdio.h>

void				draw_f(t_rtnode *ui, mglimg *layer)
{
	if (ui->type == TE_RECT)
		draw_rect(layer, (t_layer_rect *)(ui->content));
	else if (ui->type == TE_BORDER)
		draw_border(layer, (t_layer_border *)(ui->content));
	else if (ui->type == TE_CHECKBOX)
		draw_checkbox(layer, (t_layer_checkbox *)(ui->content));
	else if (ui->type == TE_LOADBAR)
		draw_loadbar(layer, (t_layer_loadbar *)(ui->content));
	else if (ui->type == TE_VARIATOR)
		draw_variator(layer, (t_layer_variator *)(ui->content));
	else if (ui->type == TE_TERM)
		draw_term(layer, (t_layer_term *)(ui->content));
}

void				draw_all(t_rtnode *ui, mglimg *layer)
{
	t_rtnode	*tmp;

	tmp = ui;
	draw_f(ui, layer);
	if (tmp->next && (((t_layer_root *)(tmp->content))->gen.show))
		draw_all(tmp->next, layer);
	if (tmp->childs && (((t_layer_root *)(tmp->content))->gen.show))
		draw_all(tmp->childs, layer);
}

int					viewer_loop(t_rt *rt)
{
	((t_layer_root *)(rt->viewer.ui->content))->gen.show = 1;
	update_ui_root_dim(rt);
	update_ui(rt->viewer.ui);
	draw_all(rt->viewer.ui, rt->viewer.layer);
	(void)rt;
	return (0);
}
