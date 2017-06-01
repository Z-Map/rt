/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:41:48 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/01 02:04:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"


int				rmmaterial(t_rtmat *mat)
{
	if (mat)
	{
		ft_vfree(mat->name);
		ft_vfree(mat);
	}
	else
		return (0);
	return (1);
}

int				rmmaterials(size_t num, ...)
{
	va_list		mats;
	size_t		i;
	int			ret;

	va_start(mats, num);
	i = 0;
	ret = 1;
	while (i < num)
	{
		if (!rmmaterial(va_arg(mats, t_rtmat *)))
			ret = 0;
	}
	va_end(mats);
	return (ret);
}
