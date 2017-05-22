/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_objects.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:56:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/22 01:34:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_OBJECTS
# define RT_DATA_OBJECTS

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"
# include "data/rt_data_material.h"
# include "data/data_matrix_parse.h"
# include "data/rt_data_render.h"
# include "generated/rt_objects_gen.h"

struct				s_rt_object_instance
{
	unsigned int	id;
	int				flags;
	char			*name;
	t_mattf			transform;
	t_mat3x2f		bounds;
	t_rtobj			*obj;
};

struct					s_rt_object_index
{
	const char			*name;
	t_rtobt				type;
	t_ui				flags;
	size_t				size;
	const t_elm			*parse_elm;
	void				(*init)(t_rtobd *);
	int					(*geometry)(t_rtobd *, t_rtray *, t_rtrgd *);
};

static const t_val	g_vtab_inst[8] = {
{VT_STR, 8, 0, 0, "name", (t_elm *)(t_ul)&g_el_str},
{VT_MATTF, 16, 1, 0, "rot", (t_elm *)(t_ul)&g_el_mattfrot},
{VT_MATTF, 16, 1, 0, "rotation", (t_elm *)(t_ul)&g_el_mattfrot},
{VT_MATTF, 16, 2, 0, "pos", (t_elm *)(t_ul)&g_el_mattftrans},
{VT_MATTF, 16, 2, 0, "position", (t_elm *)(t_ul)&g_el_mattftrans},
{VT_MATTF, 16, 3, 0, "sca", (t_elm *)(t_ul)&g_el_mattfscale},
{VT_MATTF, 16, 3, 0, "scale", (t_elm *)(t_ul)&g_el_mattfscale},
{VT_MATTF, 16, 3, 0, "size", (t_elm *)(t_ul)&g_el_mattfscale}};

static const t_elm	g_elm_inst = {"inst", sizeof(t_rtobi), 3, 8,
(t_val *)(t_ul)g_vtab_inst,NULL, NULL, NULL, NULL};


#endif
