/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:19:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/26 18:30:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "menu.h"

/*
** DONT TOUCH:
** it's magic, i mean, the kind of dark magic summoned by dark math wizard
** just go to an other file and pretent you never see this.
*/

static void		rt_event_resize_menu(t_rt *rt)
{
	rt->menu.items.x = (rt->sys.geometry.x + MENU_BORDER_X - MENU_PADDING_X) /
		(rt->menu.thumb.x + MENU_BORDER_X);
	rt->menu.items.y = (rt->sys.geometry.y + MENU_BORDER_Y - MENU_PADDING_Y) /
		(rt->menu.thumb.y + MENU_BORDER_Y);
	SDL_FreeSurface(rt->menu.background);
	menu_init_background(rt);
	menu_update_positions(rt);
}

int				rt_event_resize(SDL_Event *event, t_rt *rt)
{
	rt->sys.geometry = draw_make_px(event->window.data1,
		event->window.data2);
	if (!(rt->sys.screen = SDL_GetWindowSurface(rt->sys.win)))
		return (2);
	rt_event_resize_menu(rt);
	rt->keyboard |= FORCE_DISPLAY;
	return (0);
}
