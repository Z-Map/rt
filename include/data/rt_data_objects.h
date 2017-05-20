/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_objects.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:56:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/20 14:29:04 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_OBJECTS
# define RT_DATA_OBJECTS

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

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
	void				(*init)(t_rtobd *object);
};

/*static const t_val	g_el_inst_valtab[5] = {
{VT_STR, 0, 0, 0, "name", (t_elm *)(t_ul)&g_el_str},
{VT_MATTF, 8, 1, 0, "transform", (t_elm *)(t_ul)&g_el_}};

static const t_elm	g_el_inst = {"inst", sizeof(t_rtobi), 1, 2,
(t_val *)(t_ul)g_el_inst_valtab,
NULL, NULL, NULL, (t_elm *)(t_ul)&g_el_inst};
*/

#endif
