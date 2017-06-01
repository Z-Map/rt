/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:59:47 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/01 02:03:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

t_rtmat				*mkmaterial(const char *name)
{
	static t_vmem	*vm;
	t_rtmat			*newmat;

	if (!vm)
		vm = ft_vmemnew((sizeof(t_rtmat) + sizeof(t_vmps)) * RTMAT_MEMBUF_SIZE);
	if (!(newmat = (t_rtmat *)ft_vmemalloc(vm, sizeof(t_rtmat))))
		return (NULL);
	*newmat = (t_rtmat){.name = ft_vsdup(name),
		.color1 = (t_rgba){0, 0, 0, 0}, .color2 = (t_rgba){0, 0, 0, 0},
		.reflectivity = 0, .refraction = 0};
	return (newmat);
}

int					mkmaterials(t_rtmat **mattab, size_t num, ...)
{
	va_list			mats;
	size_t			i;

	va_start(mats, num);
	i = 0;
	while (i < num)
	{
		if (!(mattab[i] = mkmaterial(va_arg(mats, char *))))
			break ;
		i++;
	}
	va_end(mats);
	if (i != num)
	{
		while (i)
			rmmaterial(mattab[i--]);
		return (0);
	}
	return (1);
}
