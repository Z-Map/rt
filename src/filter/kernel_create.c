/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:07:00 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/27 19:55:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/vector.h"
#include "mathex/matrix.h"

t_mat3d			identity_kernel(void)
{
	t_mat3d		knl;

	knl = (t_mat3d){.x = {.x = 0, .y = 0, .z = 0},
					.y = {.x = 0, .y = 0, .z = 0},
					.z = {.x = 0, .y = 0, .z = 0}};
	return (knl);
}

t_mat3d			sharpen_kernel(void)
{
	t_mat3d		knl;

	knl = (t_mat3d){.x = {.x = 0, .y = -1, .z = 0},
					.y = {.x = -1, .y = 5, .z = -1},
					.z = {.x = 0, .y = -1, .z = 0}};
	return (knl);
}

t_mat3d			blur_kernel(void)
{
	t_mat3d		knl;

	knl = (t_mat3d){.x = {.x = -1, .y = -1, .z = -1},
					.y = {.x = -1, .y = -1, .z = -1},
					.z = {.x = -1, .y = -1, .z = -1}};
	return (knl);
}

t_mat3d			edge_kernel(void)
{
	t_mat3d		knl;

	knl = (t_mat3d){.x = {.x = -1, .y = -1, .z = -1},
					.y = {.x = -1, .y = 8, .z = -1},
					.z = {.x = -1, .y = -1, .z = -1}};
	return (knl);
}

t_mat3d			kernel_which(int knl)
{
	if (knl == 0)
		return (sharpen_kernel());
	else if (knl == 1)
		return (blur_kernel());
	else if (knl == 2)
		return (edge_kernel());
	return (identity_kernel());
}
