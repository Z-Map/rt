/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:21:36 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:21:38 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_ui_display.h"
#include "mglw/mglw.h"
#include "rt_object.h"
#include "rt_core.h"
#include "rt_tree.h"

void			event_ui(t_rt *rt)
{
	t_rtnode	*tmp;

	tmp = 0;
	rt->viewer.keys |= RTWK_REFRESH;
	ui_found_elem_with_pos(rt->viewer.ui, &tmp,\
&((t_v2i){(int)rt->viewer.mouse.x, (int)rt->viewer.mouse.y}));
	if (tmp && tmp->type == TE_CHECKBOX)
		event_click_checkbox((t_layer_checkbox *)(tmp->content));
	else if (tmp && tmp->type == TE_VARIATOR)
		event_click_variator(rt, tmp);
}
