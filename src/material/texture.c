/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:24:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/09 10:17:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "rt_texture.h"

static t_rtex	*get_valid_tex(void)
{
	t_blst		*txl;
	t_blit		it;
	t_rtex		*inst;

	if (!(txl = rtex_singletone_texlst()))
		return (NULL);
	it = ft_blststart(txl);
	while ((inst = ft_blstiter(&it)))
		if (!inst->name)
			return (inst);
	inst = ft_blststore(txl, NULL);
	return (inst);
}

t_rtex			*rtex_mktex(const char *name, size_t len)
{
	t_rtex		*tex;

	if (!(tex = get_valid_tex()))
		return (NULL);
	tex->flags = 0;
	tex->instances = 0;
	tex->name = ft_vsndup(name, len);
	tex->img = NULL;
	tex->getcol = &rtex_nocol;
	tex->getnor = &rtex_nonor;
	return (tex);
}

int				rtex_rmtex(t_rtex *tex)
{
	if (!tex || !tex->name)
		return (0);
	if (tex->img)
		mglw_rmimg(tex->img);
	tex->img = NULL;
	ft_vfree(tex->name);
	tex->name = NULL;
	return (1);
}

t_rtex			*rtex_gettex(const char *name, size_t len)
{
	t_blst		*txl;
	t_blit		it;
	t_rtex		*inst;

	if (!(txl = rtex_singletone_texlst()))
		return (NULL);
	it = ft_blststart(txl);
	while ((inst = ft_blstiter(&it)))
		if (!ft_strncmp(name, inst->name, len))
			return (inst);
	return (NULL);
}
