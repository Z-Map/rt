/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:58:22 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 19:58:37 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include <stdlib.h>

t_layer_rect		*mklayer_rect(t_v2f pos, t_v2f dim, t_v4i color,\
		int placement)
{
	t_layer_rect	*rect;

	if (!(rect = malloc(sizeof(t_layer_rect))))
		return (0);
	rect->pos = (t_v2f){pos.x, pos.y};
	rect->dim = (t_v2f){dim.x, dim.y};
	rect->color = (t_v4i){color.x, color.y, color.z, color.w};
	rect->placement = placement;
	return (rect);
}
