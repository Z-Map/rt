/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <dboudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 11:42:16 by dboudy            #+#    #+#             */
/*   Updated: 2016/07/29 14:40:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "draw.h"
# include <SDL2/SDL.h>

typedef struct			s_texture
{
	struct s_texture	*next;
	SDL_Surface			*surface;
	char				*filepath;
}						t_texture;

unsigned int			texture_color_convert(unsigned int color);
void					texture_convertformat(t_texture *tex);
t_texture				*texture_search(t_texture *tex, const char *filepath);
t_texture				*texture_create(t_texture **lst, char *filepath);
void					textures_free(t_texture *t);
t_texture				*texture_perlin(t_texture **lst, t_v2i size);

#endif
