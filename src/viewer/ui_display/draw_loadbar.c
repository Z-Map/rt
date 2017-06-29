/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loadbar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 13:51:08 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/29 18:55:43 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void				draw_loadbar(mglwin *img, t_layer_loadbar *loadbar)
{
	mglrect	rect_d;

	(void)img;
	rect_d = gen_to_rect(loadbar->gen[0], loadbar->color[0]);
	mgl_drawrect(img, rect_d);
	rect_d = gen_to_rect(loadbar->gen[1], loadbar->color[1]);
	mgl_drawrect(img, rect_d);
}
