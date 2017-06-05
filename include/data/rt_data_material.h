/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_material.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:52:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/01 02:05:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_MATERIAL_H
# define RT_DATA_MATERIAL_H

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "mglw/mglw.h"
# include "rt_prototype.h"

# define RTMAT_MEMBUF_SIZE		128

struct					s_rt_texture_instance
{
	char				*name;
	unsigned long			flags;
	t_rtex				*texture;
};

struct					s_rt_texture
{
	char				*name;
	unsigned long			flags;
	t_v2f				offset;
	mglimg				*img;
};

static const t_val			g_vtab_rtexi[1] = {
	{VT_STR, 0, 0, 0, "name", (t_elm *)(t_ul)&g_el_str}};

static const t_val			g_vtab_rtex[1] = {
	{VT_VEC2F, 0, 0, 0, "offset", (t_elm *)(t_ul)&g_el_vec2f}};

static const t_elm			g_el_texi = {"texi", sizeof(t_rtexi),
	0, 1, (t_val *)(t_ul)g_vtab_rtexi, NULL, NULL, NULL, NULL};

static const t_elm			g_el_tex = {"tex", sizeof(t_rtex),
	0, 1, (t_val *)(t_ul)g_vtab_rtex, NULL, NULL, NULL, NULL};


struct					s_rt_material
{
	char				*name;
	t_rgba				color1;
	t_rgba				color2;
	float				reflectivity;
	float				refraction;
	t_rtexi				*diffuse;
	t_rtexi				*normal;
	t_rtexi				*reflective;
};

static const t_val		g_vtab_rtmat[4] = {
	{VT_COLOR, 0, 0, 0,
		"color", (t_elm *)(t_ul)&g_el_col},
	{VT_COLOR, 4, 1, 0,
		"color2", (t_elm *)(t_ul)&g_el_col},
	{VT_FLOAT, 8, 2, 0,
		"reflectivity", (t_elm *)(t_ul)&g_el_float},
	{VT_FLOAT, 12, 3, 0,
		"refraction", (t_elm *)(t_ul)&g_el_float}};

static const t_elm		g_el_mat = {"mat", sizeof(t_rtmat),
	3, 4, (t_val *)(t_ul)g_vtab_rtmat,
	NULL, NULL, NULL, NULL};

#endif
