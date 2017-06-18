/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:34:10 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/18 21:34:48 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** kernel_calc applies the kernel filter on
** the px image, and returns the px image.
**
** A kernel filter is a 3*3 matrix that is used to apply changes to the image.
**
** For example :
**    0 -1  0
**   -1  5 -1
**    0 -1  0     is a kernel filter that sharpens the image.
** In order to apply it, we modify the pixel in the center of the kernel.
**
** The formula is for this pattern :
**
** Pixel pattern : | Kernel pattern :
**     a  b  c           1  2  3
**     d  e  f     *     4  5  6
**     g  h  i           7  8  9       is :
**
** e = (a*9) + (b*8) + (c*7) + (d*6) + (e*5) + (f*4) + (g*3) + (h*2) + (i*1)
*/

#include "rt_prototype.h"
#include "mathex/vector.h"
#include "mathex/matrix.h"

#define _

static t_v4f	t_v4f_scale(t_v4f p, double s)
{
	return ((t_v4f){.x = p.x * s, .y = p.y * s, .z = p.z * s, .w = p.w * s});
}

static t_v4f	get_new_pixel(t_v4f *p, t_mat3d knl, t_v2ui uv, t_v2ui max)
{
	double	*knlt;
	t_v4f	new;
	int		x;
	int		y;	
	
	y = -1;
	new = (t_v4f){0.0f, 0.0f, 0.0f, 0.0f};
	uv.x -= 1;
	uv.y -= 1;
	knlt = (double *)&knl;
	while ((++y < 3) && (x = -1))
		while (++x < 3)
			pv4faddv4f(&new, t_v4f_scale(p[(uv.y + y) * max.x + (uv.x + x)],
										knlt[(y * 3) + x]));
	return (new);
}

t_v4f			*kernel_calc(t_v4f *px, t_mat3d knl, t_v2ui max)
{
	t_v2ui	uv;
	t_v4f	**tmpx;

	uv.x = 0;
	tmpx = &px;
	while (++uv.x != max.x)
	{
		uv.y = 0;
		while (++uv.y != max.y)
			(*tmpx)[uv.x * max.x + uv.y] = get_new_pixel(*tmpx, knl, uv, max);
	}
	return (px);
}
