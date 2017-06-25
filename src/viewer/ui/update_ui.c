/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:59:38 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/24 21:19:04 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

static t_layer_gen	*get_gen_parent(t_rtnode *node)
{
	t_rtnode		*p;

	p = node->parent;
	return (((t_layer_gen *)(p->content)));
}

/*
** mis a jours de la position et de la dimension de la forme
*/

static void			update_rect_pos(t_layer_rect *rect,\
t_layer_gen *gen_father)
{
	rect->gen.pos.x = gen_father->pos.x +\
	(int)(rect->pos.x * gen_father->dim.x);
	rect->gen.pos.y = gen_father->pos.y +\
	(int)(rect->pos.y * gen_father->dim.y);
	rect->gen.dim.x = (int)(rect->dim.x *\
	gen_father->dim.x);
	rect->gen.dim.y = (int)(rect->dim.y *\
	gen_father->dim.y);
	main_pts_placement(rect->gen.placement, &(rect->gen.pos),\
	gen_father->dim, rect->gen.dim);
}

void				update_pos(t_layer_gen *father, t_layer_gen *stock,\
t_v2f pos, t_v2f dim)
{
	stock->pos.x = father->pos.x +\
	(int)(pos.x * father->dim.x);
	stock->pos.y = father->pos.y +\
	(int)(pos.y * father->dim.y);
	stock->dim.x = (int)(dim.x *\
	father->dim.x);
	stock->dim.y = (int)(dim.y *\
	father->dim.y);
	main_pts_placement(stock->placement, &(stock->pos),\
	father->dim, stock->dim);
}

/*
** mis a jour de al dimension et de la position en function du parent
*/

static void			update(t_rtnode *node)
{
	t_layer_gen		*gen;

	if (!(node->parent))
		return ;
	gen = get_gen_parent(node);
	if (node->type == TE_RECT || node->type == TE_BORDER ||\
	node->type == TE_CHECKBOX)
		update_rect_pos(((t_layer_rect *)(node->content)), gen);
	else if (node->type == TE_LOADBAR)
		update_loadbar(((t_layer_loadbar *)(node->content)), gen);
	else if (node->type == TE_VARIATOR)
		update_variator(((t_layer_variator *)(node->content)), gen);
}

/*
** recursif : verifier son bon deroulement
*/

void				update_ui(t_rtnode *tree)
{
	t_rtnode		*tmp;

	tmp = tree;
	update(tree);
	if (tmp->next)
		update_ui(tmp->next);
	if (tmp->childs)
		update_ui(tmp->childs);
}
