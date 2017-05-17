/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:10:23 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/16 17:11:14 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

int			**sharpen_kernel_create(void);
{
	int		knl[3][3];

	knl[0] = {0, -1, 0};
	knl[1] = {-1, 5, -1};
	knl[2] = {0, -1, 0};
	return (knl);
}

int			**blur_kernel_create(void);
{
	int		knl[3][3];

	knl[0] = {1, 1, 1};
	knl[1] = {1, 1, 1};
	knl[2] = {1, 1, 1};
	return (knl);
}

int			**edge_kernel_create(void);
{
	int		knl[3][3];

	knl[0] = {-1, -1, -1};
	knl[1] = {-1, 8, -1};
	knl[2] = {-1, -1, -1};
	return (knl);
}
