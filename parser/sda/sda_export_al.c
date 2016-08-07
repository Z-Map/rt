/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_export_al.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:17:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/08 00:30:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "libft.h"

char	*sda_export_al(t_obj *obj, t_sda_export *e)
{
	(void)e;
	if (!(obj->cfgbits & SDB_AL))
		return (NULL);
	return (sda_double_short(ft_dtoa(((t_setting*)obj->content)->al, 6)));
}
