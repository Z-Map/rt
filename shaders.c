/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:57:51 by alhote            #+#    #+#             */
/*   Updated: 2016/06/21 15:35:55 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaders.h"

t_shaders			*init_shader(unsigned int nbr_fshaders)
{
	t_shaders	*s;

	if ((s = malloc(sizeof(t_shaders))))
	{
		s->nbr_fshaders = nbr_fshaders;
		s->vertex_shader = 0;
		s->fragment_shader = malloc((sizeof(void*) * nbr_fshaders));
		return (s);
	}
	return (0);
}

int					exec_fshaders(t_shaders *s, t_render *r)
{
	unsigned int	i;

	i = 0;
	while (i < s->nbr_fshaders)
	{
		s->fragment_shader[i](r);
		++i;
	}
	if (i != 0)
		return (0);
	return (1);
}
