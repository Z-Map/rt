/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_export_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 23:40:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/17 19:07:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"
#include <stdlib.h>

char	*sda_export_size(t_obj *obj, t_sda_export *e)
{
	const float		size = ((t_cube*)obj->content)->size;

	if (FLOATCMP(size, e->setting->size))
		return (sda_double_short(ft_dtoa((double)size, 6)));
	return (NULL);
}
