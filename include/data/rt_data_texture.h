/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_texture.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:32:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:21:34 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_TEXTURE_H
# define RT_DATA_TEXTURE_H

# include "mathex/vector.h"
# include "mglw/mglw.h"
# include "rt_prototype.h"

struct					s_rt_texture
{
	char				*name;
	unsigned int		instances;
	unsigned int		flags;
	mglimg				*img;
	t_v4f				(*getcol)(t_rtex *, t_v2f);
	t_v3f				(*getnor)(t_rtex *, t_v2f);
};

struct					s_rt_texinstance
{
	unsigned int		id;
	unsigned int		flags;
	t_rtex				*tex;
	t_v2f				size;
	t_v2f				offset;
};

typedef struct			s_texinst_tracker
{
	unsigned int		id;
	unsigned int		padding;
	t_rtexi				*ti;
}						t_texiptr;

#endif
