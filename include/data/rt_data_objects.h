/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_objects.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:56:24 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/20 13:24:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_OBJECTS
# define RT_DATA_OBJECTS

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

# include "generated/rt_objects_gen.h"

struct					s_rt_object_instance
{
	unsigned int		id;
	int					flags;
	char				*name;
	t_mattf				transform;
	t_rtobj				*obj;
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

#endif
