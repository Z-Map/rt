/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:40:57 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/11 17:44:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "menu.h"
#include "libft.h"
#include "objects.h"
#include "sda.h"

static void		menu_update_params(t_rt *rt)
{
	rt->rts_size = 0;
	rt->rts = NULL;
	rt->keyboard &= FULLSCREEN;
	rt->keyboard |= FORCE_DISPLAY;
	rt->settings.cfgbits &= RT_CFGB_INMENU;
	textures_cleanup(rt->root, rt->textures);
	rt_configure_interface(&rt->interf);
}

static int		menu_click(SDL_Event *event, t_rt *rt)
{
	int		id;
	t_rt	tmp_rt;

	if (event->motion.type == SDL_MOUSEBUTTONDOWN)
	{
		id = menu_position_id(rt, event->motion.x, event->motion.y);
		ft_printf("#id: %d\n", id);
		if (id >= 0)
		{
			if ((!rt_checkcamera(&rt->rts[id])) || (!rt->rts[id].root) ||
				(!rt->rts[id].sys.screen))
				return (0);
			ft_printf("#menu: opening id: %d\n", id);
			tmp_rt = rt->rts[id];
			tmp_rt.sys = rt->sys;
			rt->rts[id].root = NULL;
			menu_clean(rt, id);
			*rt = tmp_rt;
			menu_update_params(rt);
		}
	}
	return (0);
}

static void		mouseclick_obj(t_obj *obj, t_rt *rt, const t_v2i *pos)
{
	if (!obj)
		return ;
	rt->interf.obj_selected = obj;
	if (rt->interf.flags & INTER_ENABLED)
		interface_event(pos, rt);
	rt->keyboard |= FORCE_DISPLAY;
}

int				mouseclick(SDL_Event *event, t_rt *rt)
{
	t_v2i	pos;

	SDL_GetMouseState(&pos.x, &pos.y);
	if (rt->keyboard & MENU)
		return (menu_click(event, rt));
	else if (event->motion.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			if ((rt->interf.flags & INTER_ENABLED) &&
				(interface_event(&pos, rt) > 0))
				return (0);
			mouseclick_obj(rt_obj_atpx(rt, pos), rt, &pos);
		}
	}
	return (0);
}
