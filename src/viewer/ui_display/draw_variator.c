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

void				draw_variator(mglwin *img, t_layer_variator *var)
{
	mglrect	rect_d;

	rect_d = gen_to_rect(var->gen[0], var->color[0]);
	mgl_drawrect(img, rect_d);
	rect_d = gen_to_rect(var->gen[1], var->color[1]);
	mgl_drawrect(img, rect_d);
}
