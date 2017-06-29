/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ui_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:16:08 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 16:16:19 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UI_DISPLAY_H
# define RT_UI_DISPLAY_H

# include "rt_ui.h"
# include "rt_prototype.h"
# include "mglw/mglw.h"

/*
** display rectangle on screen
*/
void	draw_rect(mglimg *img, t_layer_rect *rect);

void	draw_border(mglimg *img, t_layer_border *rect);

void	draw_checkbox(mglimg *img, t_layer_checkbox *rect);

void	draw_loadbar(mglimg *img, t_layer_loadbar *loadbar);

void	draw_variator(mglimg *img, t_layer_variator *variator);

void	draw_term(mglimg *img, t_layer_term *term);

void	draw_label(mglimg *img, t_layer_label *label);

/*
** add pixel in the image
*/
int		add_rgb_in_img(mglimg *img, unsigned int index, t_v4i color);

#endif
