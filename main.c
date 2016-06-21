/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:19:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/21 19:57:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "draw.h"
#include "libft.h"
#include "keyboard.h"
#include "parser.h"
#include "menu.h"

static int		sdl_loop(SDL_Event *event, t_rt *rt)
{
	while (SDL_PollEvent(event))
	{
		if (sdl_event(event, rt))
		{
			ft_putendl("exit requested...");
			return (1);
		}
	}
	return (0);
}

int				rt_create_window(t_rt *rt)
{
	if (draw_init(&rt->sys, draw_make_px(1024, 768), "RTv1") < 0)
		return (1);
	if (draw_init_openglcontext(&rt->sys))
		return (1);
	if (!(rt->sys.screen = SDL_GetWindowSurface(rt->sys.win)))
	{
		ft_putendl("error: failed to get sdl surface from screen");
		draw_quit(&rt->sys);
		return (1);
	}
	draw_reset_surface(rt->sys.screen, COLOR_BLACK);
	return (0);
}

int			rt_start(t_rt *rt)
{
	if (rt_create_window(rt))
		return (1);
	SDL_UpdateWindowSurface(rt->sys.win);
	while ((!sdl_loop(&rt->sys.events, rt)) && (!display(rt)))
		SDL_Delay(1);
	draw_quit(&rt->sys);
	return (0);
}

void			rt_configure(t_rt *rt)
{
	rt->sys.win = NULL;
	rt->sys.screen = NULL;
	rt->root = NULL;
	rt->rts_size = 0;
	rt->rts = NULL;
	rt->mouse = 0;
	rt->keyboard = FORCE_DISPLAY;
	rt->settings = (t_rtcfg){0.0, RTMODE};
	rt->menu.items.x = 3;
	rt->menu.items.y = 2;
	rt->menu.thumb.x = 256;
	rt->menu.thumb.y = 256;
}

int				main(int ac, char **av)
{
	t_rt	rt;

	rt_configure(&rt);
	if (ac == 1)
		menu_init(&rt);
	else if (ac >= 2)
	{
		if (!(rt.root = yolo_parse(av[1], &(rt.settings))))
		{
			ft_putendl_fd("error.", 2);
			return (1);
		}
		if (rt.root->content)
		{
			rt_node_foreach(rt.root, INFIX, rt_node_display, NULL);
			ft_putchar('\n');
			rt_start(&rt);
		}
		else
			ft_putstr("no camera\n");
		rt_node_free(rt.root);
	}
	return (0);
}
