/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mgr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:26:12 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 05:49:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_core.h"
#include "rt_texture.h"

t_blst				*rtex_singletone_texlst(void)
{
	static t_blst	*texlst;

	if (!texlst)
	{
		texlst = ft_blstnew(sizeof(t_rtex), 32);
		if (!texlst)
			rt_error(125, "Unable to allocate texture slot");
	}
	return (texlst);
}

t_blst				*rtex_singletone_texilst(void)
{
	static t_blst	*texilst;

	if (!texilst)
	{
		texilst = ft_blstnew(sizeof(void *) + (sizeof(t_ui) * 2), 64);
		if (!texilst)
			rt_error(126, "Unable to allocate texinstance slot");
	}
	return (texilst);
}
