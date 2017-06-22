/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checkbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:21:02 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/22 19:21:08 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_ui_display.h"

void	event_click_checkbox(t_layer_checkbox *cb)
{
	if (cb->state == 1)
		cb->state = 0;
	else
		cb->state = 1;
}
