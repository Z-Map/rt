/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_texture.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:32:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 06:30:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_TEXTURE_H
#define RT_DATA_TEXTURE_H

# include "mathex/vector.h"
# include "mglw/mglw.h"
# include "rt_prototype.h"

# define TEXPROC_NUM			5

static const char			*g_procedural_texlist[] = {
	"perlin", "trigo", "circle", "strip", "chess"};

struct					s_rt_texture
{
	char				*name;
	unsigned int		instances;
	unsigned int		flags;
	mglimg				*img;
};

struct					s_rt_texture_instance
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
