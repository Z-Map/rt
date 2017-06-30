/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:41:58 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 22:42:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"
#include "mglw/data/rect.h"
#include "mathex/color.h"

void				draw_rect(mglwin *img, t_layer_rect *rect)
{
	mglrect rect_d;

	rect_d = gen_to_rect(rect->gen, rect->color);
	mgl_drawrect(img, rect_d);
}
