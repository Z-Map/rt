/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:11:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/15 20:50:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

size_t				obj_type_memsize(t_rtobt type)
{
	const size_t	sizes[14] = { sizeof(struct s_rtscene),
		sizeof(struct s_rtempty), sizeof(struct s_rtcamera),
		sizeof(struct s_rtplan), sizeof(struct s_rtsphere),
		sizeof(struct s_rtcone), sizeof(struct s_rtcylinder),
		sizeof(struct s_rtcuboid), sizeof(struct s_rtplan),
		sizeof(struct s_rtmesh), sizeof(struct s_rtlight),
		sizeof(struct s_rtlight), sizeof(struct s_rtlight), 8};
	size_t			*size;
	unsigned int	i;

	size = sizes;
	i = SCENE;
	while (!(i & type) && !(i & NOTYPE))
	{
		size++;
		i <<= 1;
	}
	return ((sizeof(t_rtobj) - sizeof(t_rtobd)) + *size);
}
