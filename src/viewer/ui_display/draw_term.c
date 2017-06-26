/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:55:19 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/26 15:55:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void			draw_term(mglimg *img, t_layer_term *term)
{
	t_layer_rect	rect;

	rect = (t_layer_rect){.gen = term->gen, .color = term->color};
	draw_rect(img, &rect);
}
