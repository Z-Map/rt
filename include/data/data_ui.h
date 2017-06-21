/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_ui.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:54:21 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/21 23:17:36 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_UI_H
# define DATA_UI_H

# include "mathex/vector.h"
# include "rt_prototype.h"

enum			e_type_element
{
	TE_ROOT,
	TE_RECT,
	TE_CARRY,
	TE_BORDER,
	TE_ERR
};

enum			e_type_placement
{
	PL_NONE,
	PL_TOP,
	PL_BOTTOM,
	PL_LEFT,
	PL_RIGHT,
	PL_MIDDLE
};

/*
** generic data
*/
struct			s_layer_generic
{
	int			id;
	int			show;
	t_v2i		pos;
	t_v2i		dim;
	int			placement;
};

/*
** element pere de tout les peres
*/

struct			s_layer_root
{
	t_layer_gen	gen;
};

struct			s_layer_rect
{
	t_layer_gen	gen;
	t_v2f		pos;
	t_v2f		dim;
	t_v4i		color;
};

struct			s_layer_border
{
	t_layer_gen	gen;
	t_v2f		pos;
	t_v2f		dim;
	t_v4i		color;
	int			border_display;
	float		dim_border;
	int			valid_border;
};

#endif
