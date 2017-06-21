#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

static t_layer_gen	*get_gen_parent(t_rtnode *node)
{
	t_rtnode *p;

	p = node->parent;
	return (((t_layer_gen *)(p->content)));
}

/*
** mis a jours de la position et de la dimension de la forme
*/
static void	update_rect_pos(t_layer_rect *rect, t_layer_gen *gen_father)
{
	rect->gen.pos.x = gen_father->pos.x + (int)(rect->pos.x * gen_father->dim.x);
        rect->gen.pos.y = gen_father->pos.y + (int)(rect->pos.y * gen_father->dim.y);
	rect->gen.dim.x = (int)(rect->dim.x * gen_father->dim.x);
	rect->gen.dim.y = (int)(rect->dim.y * gen_father->dim.y);
	main_pts_placement(rect->gen.placement, &(rect->gen.pos), gen_father->dim, rect->gen.dim);
}

/*
** mis a jour de al dimension et de la position en function du parent
*/
static void update(t_rtnode *node)
{
	t_layer_gen *gen;

	if (!(node->parent))
		return ;
	gen = get_gen_parent(node);
	if (node->type == TE_RECT || node->type == TE_BORDER) // mis a jour de la position
		update_rect_pos(((t_layer_rect *)(node->content)), gen);
}

/*
* recursif : verifier son bon deroulement
*/
void	update_ui(t_rtnode *tree)
{
	t_rtnode *tmp;

	tmp = tree;
	update(tree);
	if (tmp->next)
		update_ui(tmp->next); //rappel recursif
	if (tmp->childs)
		update_ui(tmp->childs);
}
