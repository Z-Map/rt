/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:11:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/20 14:36:51 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generated/rt_typetab_gen.h"

// size_t				obj_type_memsize(t_rtobt type)
// {
// 	const size_t	sizes[14] = { sizeof(struct s_rtscene),
// 		sizeof(struct s_rtempty), sizeof(struct s_rtcamera),
// 		sizeof(struct s_rtplan), sizeof(struct s_rtsphere),
// 		sizeof(struct s_rtcone), sizeof(struct s_rtcylinder),
// 		sizeof(struct s_rtcuboid), sizeof(struct s_rtplan),
// 		sizeof(struct s_rtmesh), sizeof(struct s_rtpointlight),
// 		sizeof(struct s_rtsunlight), sizeof(struct s_rtspot), 8};
// 	const size_t	*size;
// 	unsigned int	i;
//
// 	size = sizes;
// 	i = SCENE;
// 	while (!(i & type) && !(i & NOTYPE))
// 	{
// 		size++;
// 		i <<= 1;
// 	}
// 	return (*size);
// }

size_t				obj_type_memsize(t_rtobt type)
{
	int				i;

	if ((i = obj_type_search(type)) < 0)
		return (0);
	return (g_obt_tab[i].size);
}

int					obj_type_search(t_rtobt type)
{
	const t_rtobind	*tab = g_obt_tab;
	size_t			len;

	len = RT_OBT_TAB_LEN;
	while (len--)
	{
		if (type == tab[len].type)
			return (len);
	}
	return (-1);
}

int					obj_typename_search(const char *name)
{
	const t_rtobind	*tab = g_obt_tab;
	size_t			len;

	len = RT_OBT_TAB_LEN;
	while (len--)
	{
		if (ft_strequ(name, tab[len].name))
			return (len);
	}
	return (-1);
}
