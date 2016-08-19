/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interf_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <dboudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 10:39:45 by dboudy            #+#    #+#             */
/*   Updated: 2016/08/19 01:41:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

SDL_Rect	*define_position(SDL_Rect *pos, Uint8 x, Uint8 y)
{
	pos->x = x;
	pos->y = y;
	return (pos);
}

SDL_Color	*define_color(SDL_Color *color, Uint8 r, Uint8 g, Uint8 b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

TTF_Font	*define_police(TTF_Font *police, char *name, int size, int selected)
{

	if ((police = TTF_OpenFont(name, size)) != NULL)
	{
		if (selected)
			TTF_SetFontStyle(police, TTF_STYLE_UNDERLINE);
		return (police);
	}
	else
		ft_putstr("fail open font\n");
	return (NULL);
}

SDL_Surface	*define_texte(TTF_Font *police, char *txt, SDL_Color *color)
{
	SDL_Surface	*texte;

	if (!txt)
		return (NULL);
	if ((texte = TTF_RenderText_Blended(police, txt, *color)) != NULL)
		return (texte);
	else
		ft_putstr("fail define texte\n");
	return (NULL);
}

/*
define_font_size;
*/
