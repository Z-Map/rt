/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:16:41 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:15:48 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "rt_texture.h"

t_rtex			*rtex_load(t_rtex *tex)
{
	if (!tex || !tex->name || (tex->flags & (TEX_LOADED | TEX_PROCEDURALE)))
		return (tex);
	if (tex->img)
		mglw_rmimg(tex->img);
	if (!(tex->img = mglw_loadimage(tex->name, MGLWI_NONE, 4)))
		return (tex);
	tex->flags |= TEX_LOADED;
	tex->getcol = &rtex_uvimage_col;
	tex->getnor = &rtex_uvimage_nor;
	return (tex);
}
