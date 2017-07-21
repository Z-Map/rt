/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_material.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:52:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:18:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_MATERIAL_H
# define RT_DATA_MATERIAL_H

# include "mathex/color.h"
# include "mathex/matrix.h"
# include "mglw/mglw.h"
# include "rt_prototype.h"
# include "rt_texture.h"

# define RTMAT_MEMBUF_SIZE		128

static const t_elm		g_el_texi = {"texi", sizeof(t_rtexi),
	0, 0, NULL, NULL, NULL, texture_parse, NULL};

struct					s_rt_material
{
	char				*name;
	t_rgba				color1;
	t_rgba				color2;
	float				reflectivity;
	float				refraction;
	t_rtexi				diffuse;
	t_rtexi				normal;
	t_rtexi				reflective;
	float				spec;
	int					padding;
};

static const t_val		g_vtab_rtmat[14] = {
	{VT_COLOR, 8, 0, 0, "color", (t_elm *)(t_ul)&g_el_col},
	{VT_COLOR, 12, 1, 0, "color2", (t_elm *)(t_ul)&g_el_col},
	{VT_FLOAT, 16, 2, 0, "reflectivity", (t_elm *)(t_ul)&g_el_float},
	{VT_FLOAT, 20, 3, 0, "refraction", (t_elm *)(t_ul)&g_el_float},
	{VF_ELEMENT, 24, 4, 0, "diffuse", (t_elm *)(t_ul)&g_el_texi},
	{VT_FLOAT, 40, 7, 0, "diffuse.scale", (t_elm *)(t_ul)&g_el_vec2f},
	{VT_FLOAT, 48, 8, 0, "diffuse.offset", (t_elm *)(t_ul)&g_el_vec2f},
	{VF_ELEMENT, 56, 5, 0, "normal", (t_elm *)(t_ul)&g_el_texi},
	{VT_FLOAT, 72, 9, 0, "normal.scale", (t_elm *)(t_ul)&g_el_vec2f},
	{VT_FLOAT, 88, 10, 0, "normal.offset", (t_elm *)(t_ul)&g_el_vec2f},
	{VF_ELEMENT, 96, 6, 0, "reflective", (t_elm *)(t_ul)&g_el_texi},
	{VT_FLOAT, 112, 11, 0, "reflective.scale", (t_elm *)(t_ul)&g_el_vec2f},
	{VT_FLOAT, 120, 12, 0, "reflective.offset", (t_elm *)(t_ul)&g_el_vec2f},
	{VT_FLOAT, 128, 13, 0, "specular", (t_elm *)(t_ul)&g_el_float}};

static const t_elm		g_el_mat = {"mat", sizeof(t_rtmat),
	13, 14, (t_val *)(t_ul)g_vtab_rtmat, NULL, NULL, NULL, NULL};

#endif
