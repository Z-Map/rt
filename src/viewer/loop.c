/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:20:36 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 16:47:28 by lcarreel         ###   ########.fr       */
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
//	printf("\t ---> %d | %d\n", ui->flags, ui->type);
	if (ui->type == TE_RECT)
	{
		printf("Draw rect ... : %d\n", ui->flags);
		draw_rect(layer, (t_layer_rect *)(ui->content));
	}
}

void				draw_all(t_rtnode *ui, mglimg *layer)
{
        t_rtnode **tmp;

        tmp = &ui;
        while (*tmp)
        {
                //update(tree);
		printf("--> %d\n", ui->flags);
		draw_f(ui, layer);
                if ((*tmp)->childs)
                        draw_all((*tmp)->childs, layer); //rappel recursif
                tmp = &((*tmp)->next);
        }
}

int				viewer_loop(t_rt *rt)
{
	update_ui_root_dim(rt);
	update_ui(rt->viewer.ui);
	draw_all(rt->viewer.ui, rt->viewer.layer);
	(void)rt;
	return (0);
}
