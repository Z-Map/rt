/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:31:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 05:48:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEXTURE_H
#define RT_TEXTURE_H

# include "rt_prototype.h"
# include "data/rt_data_texture.h"

t_blst		*rtex_singletone_texlst(void);
t_blst		*rtex_singletone_texilst(void);

t_rtex		*rtex_mktex(const char *name, size_t len);
int			rtex_rmtex(t_rtex *tex);
t_rtex		*rtex_gettex(const char *name, size_t len);
int			rtex_mkinstance(const char *name, size_t len, t_rtexi *ti);
int			rtex_rminstance(t_rtexi *ti);

int			texture_parse(t_val *val, void *mem, t_gparse parser);

#endif
