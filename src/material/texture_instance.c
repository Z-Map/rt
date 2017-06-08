/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 02:43:19 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/08 05:55:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_texture.h"

static t_texiptr	*get_valid_texinst(void)
{
	static t_ui		id = 1;
	t_blst			*til;
	t_blit			it;
	t_texiptr		*inst;
	t_texiptr		ninst;

	if (!(til = rtex_singletone_texilst()))
		return (NULL);
	it = ft_blststart(til);
	while ((inst = ft_blstiter(&it)))
		if (!inst->ti)
			return (inst);
	ninst = (t_texiptr){0, 0, NULL};
	inst = ft_blststore(til, &ninst);
	if (inst)
		inst->id = id++;
	return (inst);
}

static t_texiptr	*get_texiptr(t_rtexi *ti)
{
	t_blst			*til;
	t_texiptr		*inst;

	if (!(til = rtex_singletone_texilst()) || !ti || !ti->id)
		return (NULL);
	inst = (t_texiptr *)ft_blstget(til, ti->id);
	if (!inst || (inst->ti != ti))
		return (NULL);
	return (inst);
}

int					rtex_mkinstance(const char *name, size_t len, t_rtexi *ti)
{
	t_texiptr		*inst;

	if (!ti)
		return (0);
	inst = get_texiptr(ti);
	if (inst)
		ti->tex->instances -= 1;
	else if (!(inst = get_valid_texinst()))
		return (0);
	inst->ti = ti;
	ti->id = inst->id;
	ti->flags = 0;
	if (!(ti->tex = rtex_gettex(name, len)))
		ti->tex = rtex_mktex(name, len);
	if (ti->tex)
	{
		ti->flags |= TEX_VALID;
		ti->tex->instances += 1;
	}
	return ((ti->tex) ? 1 : 0);
}

int					rtex_rminstance(t_rtexi *ti)
{
	t_texiptr		*inst;

	if (!ti || !(inst = get_texiptr(ti)))
		return (0);
	inst->ti = NULL;
	ti->flags = 0;
	ti->tex->instances -= 1;
	return (1);
}
