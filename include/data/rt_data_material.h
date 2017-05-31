/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_material.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:52:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/31 18:55:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_MATERIAL_H
# define RT_DATA_MATERIAL_H

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "mglw/mglw.h"
# include "rt_prototype.h"

# define RTMAT_MEMBUF_SIZE		128

struct					s_rt_material
{
	char				*name;
	t_rgba				color1;
	t_rgba				color2;
	float				reflectivity;
	float				refraction;
	t_rtex				*texture;
	t_rtex				*diffuse;
	t_rtex				*normal;
	t_rtex				*reflective;
};

static const t_val		g_vtab_rtmat[5] = {
	{VT_COLOR, 8, 0, 0,
		"color", (t_elm *)(t_ul)&g_el_col},
	{VT_COLOR, 12, 1, 0,
		"color2", (t_elm *)(t_ul)&g_el_col},
	{VT_FLOAT, 16, 2, 0,
		"reflectivity", (t_elm *)(t_ul)&g_el_float},
	{VT_FLOAT, 20, 3, 0,
		"refraction", (t_elm *)(t_ul)&g_el_float}};

static const t_elm		g_el_mat = {"mat", sizeof(t_rtmat),
	3, 4, (t_val *)(t_ul)g_vtab_rtmat,
	NULL, NULL, NULL, NULL};

struct					s_rt_texture
{
	char				*name;
	unsigned long		flags;
	mglimg				*img;
};

#endif
