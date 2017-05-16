/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:34:10 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/14 16:20:07 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** kernel_calc applies the kernel filter on the px image, and returns the px image.
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
**/

#include "rt_prototype.h"
#include "mathex/vector.h"

static void		get_new_pixel(t_rgba px, int knl[3][3], int i, int j)
{
	t_rgba	new;

	new = px[(i - 1) * max.x + j - 1] * knl[i + 1][j + 1]
		+ px[(i - 1) * max.x + j] * knl[i + 1][j]
		+ px[(i - 1) * max.x + j + 1] * knl[i + 1][j - 1]
		+ px[i * max.x + j - 1] * knl[i][j + 1]
		+ px[i * max.x + j] * knl[i][j]
		+ px[i * max.x + j + 1] * knl[i][j - 1]
		+ px[(i + 1) * max.x + j - 1] * knl[i - 1][j + 1]
		+ px[(i + 1) * max.x + j] * knl[i - 1][j]
		+ px[(i + 1) * max.x + j + 1] * knl[i - 1][j + 1];
		px[i * max.x + j] = new;
}

t_rgba			kernel_calc(t_rgba *px, int knl[3][3], t_v2ui max)
{
	int		i;
	int		j;
	t_rgba	**tmpx;

	i = 0;
	tmpx = &px;
	while (++i != max.x)
	{
		j = 0;
		while (++j != max.y)
			(*tmpx)[i * max.x + j] = get_new_pixel(*tmpx, knl, i, j);
	}
	return (px);
}
