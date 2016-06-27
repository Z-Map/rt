/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:19:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/27 13:49:21 by snicolet         ###   ########.fr       */
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
	const t_point	*geo = &rt->sys.geometry;
	int				d;

	d = rt->menu.thumb.x + MENU_BORDER_X;
	rt->menu.items.x = (d) ? (geo->x + MENU_BORDER_X - MENU_PADDING_X) / d : 0;
	d = rt->menu.thumb.y + MENU_BORDER_Y;
	rt->menu.items.y = (d) ? (geo->y + MENU_BORDER_Y - MENU_PADDING_Y) / d : 0;
	menu_background_update(rt);
	menu_update_positions(rt);
}

int				rt_event_resize(SDL_Event *event, t_rt *rt)
{
	rt->sys.geometry = draw_make_px(event->window.data1,
		event->window.data2);
	if (!(rt->sys.screen = SDL_GetWindowSurface(rt->sys.win)))
		return (2);
	if (rt->keyboard & MENU)
		rt_event_resize_menu(rt);
	rt->keyboard |= FORCE_DISPLAY;
	return (0);
}
