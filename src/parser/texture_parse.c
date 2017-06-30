/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:05:08 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/27 19:53:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_texture.h"

static int	tp_parse(const char *name, size_t len, t_val *val, void *mem)
{
	size_t	i;
	size_t	l;

	i = TEXPROC_NUM;
	while (i--)
	{
		l = ft_strlen(g_procedural_texlist[i]);
		if ((l <= len) && !ft_strncmp(name, g_procedural_texlist[i], l))
		{
			rtex_mkinstance(g_procedural_texlist[i], l,
				(t_rtexi *)(mem + val->offset));
			return (1);
		}
	}
	return (0);
}

static int	ti_parse(const char *name, size_t len, t_val *val, void *mem)
{
	rtex_mkinstance(name, len, (t_rtexi *)(mem + val->offset));
	return (1);
}

int			texture_parse(t_val *val, void *mem, t_gparse parser)
{
	int		ret;

	ret = 0;
	if (!parser.value || (ft_prstrim(&(parser.value), &(parser.v_len),
		FT_WHITESPACE) && !parser.v_len))
		return (0);
	if (!ft_strconcur(parser.value, "tp_"))
		ret = tp_parse(parser.value + 3, parser.v_len - 3, val, mem);
	else
		ret = ti_parse(parser.value, parser.v_len, val, mem);
	return (ret);
}
