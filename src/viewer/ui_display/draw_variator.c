/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_variator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:00:46 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/24 21:00:57 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"
#include <stdio.h>

void				draw_variator(mglimg *img, t_layer_variator *var)
{
	t_layer_rect	c[2];

	c[0] = (t_layer_rect){.gen = var->gen[0], .color = var->color[0]};
	c[1] = (t_layer_rect){.gen = var->gen[1], .color = var->color[1]};
	draw_rect(img, &(c[0]));
	draw_rect(img, &(c[1]));
}
