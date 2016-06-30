/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:40:57 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/30 19:56:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "menu.h"
#include "libft.h"

static int		menu_click(SDL_Event *event, t_rt *rt)
{
	int		id;
	t_rt	tmp_rt;

	if (event->motion.type == SDL_MOUSEBUTTONDOWN)
	{
		id = menu_position_id(rt, event->motion.x, event->motion.y);
		ft_printf("id: %d\n", id);
		if (id >= 0)
		{
			if (!rt_checkcamera(&rt->rts[id]))
				return (0);
			ft_printf("menu: opening id: %d\n");
			tmp_rt = rt->rts[id];
			tmp_rt.sys = rt->sys;
			rt->rts[id].root = NULL;
			menu_clean(rt);
			*rt = tmp_rt;
			rt->rts_size = 0;
			rt->rts = NULL;
			rt->keyboard &= FULLSCREEN;
			rt->keyboard |= FORCE_DISPLAY;
		}
	}
	return (0);
}

int				mouseclick(SDL_Event *event, t_rt *rt)
{
	if (rt->keyboard & MENU)
		return (menu_click(event, rt));
	if (event->motion.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event->button.button == SDL_BUTTON_LEFT)
			rt->keyboard |= ZOOMIN;
		else if (event->button.button == SDL_BUTTON_RIGHT)
			rt->keyboard |= ZOOMOUT;
	}
	else
	{
		if ((event->button.button == SDL_BUTTON_LEFT) &&
			(rt->keyboard & ZOOMIN))
			rt->keyboard ^= ZOOMIN;
		else if ((event->button.button == SDL_BUTTON_RIGHT) &&
			(rt->keyboard & ZOOMOUT))
			rt->keyboard ^= ZOOMOUT;
	}
	return (0);
}
