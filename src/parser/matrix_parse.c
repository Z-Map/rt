/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:19:18 by lcarreel          #+#    #+#             */
/*   Updated: 2017/06/22 19:34:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/vector.h"
#include "rt_parser.h"

int				vparse_rot(t_val *val, void *mem, t_gparse parser)
{
	const t_val	cv = {VT_VEC3F, 0, 0, 0, "mattf", (t_elm *)(t_ul)&g_el_vec3f};
	t_v3f		offset;
	t_v3f		vec;
	int			ret;

	vec = (t_v3f){0.0f, 0.0f, 0.0f};
	parser.mem = &vec;
	parser.cfgbits = NULL;
	ret = ft_vparse_vec((t_val *)(t_ul)&cv, &vec, parser);
	if (ret < 0)
		return (ret);
	vec = v3fmulv3f(v3fdivv3f(vec, nv3f(180)), nv3f(M_PI));
	offset = ((t_mattf *)((t_ul)mem + val->offset))->offset;
	((t_mattf *)((t_ul)mem + val->offset))->offset = nv3f(0.0);
	pmattf_rot((t_mattf *)((t_ul)mem + val->offset), vec);
	((t_mattf *)((t_ul)mem + val->offset))->offset = offset;
	return (ret);
}

int				vparse_scale(t_val *val, void *mem, t_gparse parser)
{
	const t_val	cv = {VT_VEC3F, 0, 0, 0, "mattf", (t_elm *)(t_ul)&g_el_vec3f};
	t_v3f		vec;
	int			ret;

	vec = (t_v3f){0.0f, 0.0f, 0.0f};
	parser.mem = &vec;
	parser.cfgbits = NULL;
	ret = ft_vparse_vec((t_val *)(t_ul)&cv, &vec, parser);
	if (ret < 0)
		return (ret);
	pmattf_scalv((t_mattf *)((t_ul)mem + val->offset), vec);
	return (ret);
}

int				vparse_trans(t_val *val, void *mem, t_gparse parser)
{
	const t_val	cv = {VT_VEC3F, 0, 0, 0, "mattf", (t_elm *)(t_ul)&g_el_vec3f};
	t_v3f		vec;
	int			ret;

	vec = (t_v3f){0.0f, 0.0f, 0.0f};
	parser.mem = &vec;
	parser.cfgbits = NULL;
	ret = ft_vparse_vec((t_val *)(t_ul)&cv, &vec, parser);
	if (ret < 0)
		return (ret);
	((t_mattf *)((t_ul)mem + val->offset))->offset = vec;
	return (ret);
}
