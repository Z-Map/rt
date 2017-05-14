/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_material.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:52:02 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/25 20:51:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_MATERIAL_H
# define RT_DATA_MATERIAL_H

# include "mathex/vector.h"
# include "mathex/matrix.h"
# include "rt_prototype.h"

# define RTMAT_MEMBUF_SIZE		128

struct			s_rt_material
{
	char			*name;
	t_rgba			color1;
	t_rgba			color2;
	float			reflectivity;
	float			refraction;
};

#endif
