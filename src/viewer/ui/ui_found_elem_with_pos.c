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
	if (ui_is_event(((t_layer_root *)(tmp->content))->gen) &&\
	ui_check_hit(tmp, pos_cursor))
		*found = tmp;
}
