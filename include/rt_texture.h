/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:31:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:34:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEXTURE_H
# define RT_TEXTURE_H

# include "rt_prototype.h"
# include "data/rt_data_texture.h"

# define TEXPROC_NUM			0

t_blst		*rtex_singletone_texlst(void);
t_blst		*rtex_singletone_texilst(void);

t_rtex		*rtex_mktex(const char *name, size_t len);
int			rtex_rmtex(t_rtex *tex);
t_rtex		*rtex_gettex(const char *name, size_t len);
t_rtex		*rtex_load(t_rtex *tex);
int			rtex_mkinstance(const char *name, size_t len, t_rtexi *ti);
int			rtex_rminstance(t_rtexi *ti);

int			texture_parse(t_val *val, void *mem, t_gparse parser);

t_v4f		rtex_nocol(t_rtex *tex, t_v2f uv);
t_v3f		rtex_nonor(t_rtex *tex, t_v2f uv);
t_v4f		rtex_uvimage_col(t_rtex *tex, t_v2f uv);
t_v3f		rtex_uvimage_nor(t_rtex *tex, t_v2f uv);

static const char			*g_procedural_texlist[] = {
	"perlin", "trigo", "bubble", "circle", "strip", "chess"};

float		rtex_proc_perlin(t_v3f vec);
float		rtex_proc_trigo(t_v3f vec);
float		rtex_proc_bubble(t_v3f vec);
float		rtex_proc_circle(t_v3f vec);
float		rtex_proc_stripx(t_v3f vec);
float		rtex_proc_stripy(t_v3f vec);
float		rtex_proc_stripz(t_v3f vec);
float		rtex_proc_chess(t_v3f vec);

float		lerp(float factor, float v1, float v2);

#endif
