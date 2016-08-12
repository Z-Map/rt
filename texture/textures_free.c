/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 21:48:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/12 12:48:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "SDL2/SDL.h"
#include <stdlib.h>

void	textures_freetex(t_texture *t)
{
	if (!t)
		return ;
	SDL_FreeSurface(t->surface);
	free(t->filepath);
	free(t);
}

void	textures_free(t_texture *t)
{
	if (!t)
		return ;
	if (t->next)
		textures_free(t->next);
	textures_freetex(t);
}