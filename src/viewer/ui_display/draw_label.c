/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:48:39 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/26 17:48:41 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

void	draw_label(mglwin *img, t_layer_label *label)
{
	float pos[2];

	pos[0] = label->gen.dim.x;
	pos[1] = label->gen.dim.y;
	mgl_drawmglstr(img, label->data, pos, 10, 0xFF00FF64);
}
