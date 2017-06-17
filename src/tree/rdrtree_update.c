/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrtree_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:14:35 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/16 16:16:12 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_texture.h"
#include "rt_render.h"

static int		load_tex(void *inst, void *env)
{
	t_rtobd		*o;

	(void)env;
	if (inst && (((t_rtobi *)inst)->obj->type & (VISIBLE | SCENE)))
	{
		o = (t_rtobd *)(((t_rtobi *)inst)->obj);
		if (o->plan.material->diffuse.flags & TEX_VALID)
			rtex_load(o->plan.material->diffuse.tex);
		if (o->plan.material->normal.flags & TEX_VALID)
			rtex_load(o->plan.material->normal.tex);
		if (o->plan.material->reflective.flags & TEX_VALID)
			rtex_load(o->plan.material->reflective.tex);
	}
	return (0);
}

int				rtree_update(t_rdrtree *tree)
{
	// size_t	i;
	tree->visible = node_tabfromtype((t_rtree *)tree, VISIBLE,
		&(tree->visible_len));
	tree->lights = node_tabfromtype((t_rtree *)tree, LIGHT,
		&(tree->lights_len));
	tree_find((t_rtnode *)tree, &load_tex, NULL);
	// tree->negative = node_tabfromtype(tree, VISIBLE, &(tree->negative_len));
	// if (tree->visible)
	// {
	// 	i = tree->visible_len;
	// 	while (i-- > 1)
	// 	{
	// 		if (tree->visible[i])
	// 			ft_printf("(%s), ", tree->visible[i]->content->obj->name);
	// 		else
	// 			ft_printf("!ERROR!, ");
	// 	}
	// 	if (tree->visible[i])
	// 		ft_printf("(%s)\n", tree->visible[i]->content->obj->name);
	// 	else
	// 		ft_printf("!ERROR!, ");
	// }
	return (1);
}
