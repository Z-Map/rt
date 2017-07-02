/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:20:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/02 14:59:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_viewer.h"
#include "rt_prototype.h"
#include "data/rt_data_viewer.h"
#include "rt_ui_display.h"
#include "data/rt_data_tree.h"
#include <stdio.h>

void				draw_f(t_rtnode *ui, mglwin *win)
{
	if (ui->type == TE_RECT)
		draw_rect(win, (t_layer_rect *)(ui->content));
	else if (ui->type == TE_CHECKBOX)
		draw_checkbox(win, (t_layer_checkbox *)(ui->content));
	else if (ui->type == TE_LOADBAR)
		draw_loadbar(win, (t_layer_loadbar *)(ui->content));
	else if (ui->type == TE_VARIATOR)
		draw_variator(win, (t_layer_variator *)(ui->content));
	else if (ui->type == TE_TERM)
		draw_term(win, (t_layer_term *)(ui->content));
	else if (ui->type == TE_LABEL)
		draw_label(win, (t_layer_label *)(ui->content));
}

void				draw_all(t_rtnode *ui, mglwin *win)
{
	t_rtnode	*tmp;

	tmp = ui;
	draw_f(ui, win);
	if (tmp->next && (((t_layer_root *)(tmp->content))->gen.show))
		draw_all(tmp->next, win);
	if (tmp->childs && (((t_layer_root *)(tmp->content))->gen.show))
		draw_all(tmp->childs, win);
}

/*
** draw_all(rt->viewer.ui, rt->viewer.win);
*/

int					viewer_loop(t_rt *rt)
{
	((t_layer_root *)(rt->viewer.ui->content))->gen.show = 1;
	update_ui_root_dim(rt);
	update_ui(rt->viewer.ui);
	draw_all(rt->viewer.ui, rt->viewer.win);
	return (0);
}
