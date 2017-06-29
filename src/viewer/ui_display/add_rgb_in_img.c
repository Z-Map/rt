/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rgb_in_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:41:42 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 22:41:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui_display.h"
#include "mathex/vector.h"

int	add_rgb_in_img(mglimg *img, unsigned int index, t_v4f color)
{
	if (index + 3 >= img->memlen)
		return (0);
	img->pixels[index] = (int)color.x;
	img->pixels[index + 1] = (int)color.y;
	img->pixels[index + 2] = (int)color.z;
	img->pixels[index + 3] = (int)color.w;
	return (1);
}
