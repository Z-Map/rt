/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_found_elem_with_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:13:37 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:25:51 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

/*
void			ui_found_elem_with_pos(t_rtnode *node,\
t_rtnode **found, t_v2i *pos_cursor)
{
	t_rtnode	*tmp;

	if (*found)
	{
		printf("Ned ...\n");
		return ;
	}
	tmp = node;
	if (tmp)
		printf("---> Actual id : %d\n", tmp->flags);
	if (tmp->next)
		printf("---> Next : %d.\n", tmp->next->flags);
	if (tmp->childs)
		printf("---> Childs : %d.\n", tmp->childs->flags);
	if (tmp->next && (((t_layer_root *)(tmp->next->content))->gen.show) &&\
	ui_check_hit(tmp->next, pos_cursor))
	{
		printf("Next --> %d:)\n", tmp->next->flags);
		ui_found_elem_with_pos(tmp->next, found, pos_cursor);
	}
	if ((tmp->childs && (((t_layer_root *)(tmp->childs->content))->gen.show) &&\
	ui_check_hit(tmp->childs, pos_cursor)) || (tmp->childs && tmp->childs->next && tmp->parent->type == TE_ROOT))
	{
		printf("Childs --> %d\n", tmp->childs->flags);
		ui_found_elem_with_pos(tmp->childs, found, pos_cursor);
	}
	if (ui_is_event(((t_layer_root *)(tmp->content))->gen) && ui_check_hit(tmp, pos_cursor))
	{
		printf("HIt ...\n");
		*found = tmp;
	}
	printf("\n\n");
}
*/

void	ui_found_elem_with_pos(t_rtnode *node,\
t_rtnode **found, t_v2i *pos_cursor)
{
	t_rtnode	*tmp;

	if (*found)
		return ;
	tmp = node;
	if (tmp->next)
		ui_found_elem_with_pos(tmp->next, found, pos_cursor);
	if (tmp->childs)
		ui_found_elem_with_pos(tmp->childs, found, pos_cursor);
	if (ui_is_event(((t_layer_root *)(tmp->content))->gen) && ui_check_hit(tmp, pos_cursor))
		*found = tmp;
}
