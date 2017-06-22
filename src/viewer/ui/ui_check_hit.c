#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

int	ui_check_hit(t_rtnode *node, t_v2i *pos_cursor)
{
	t_layer_gen gen;

	gen = ((t_layer_root *)(node->content))->gen;
	if (pos_cursor->x < gen.pos.x + gen.dim.x && pos_cursor->x > gen.pos.x &&\
	    pos_cursor->y < gen.pos.y + gen.dim.y && pos_cursor->y > gen.pos.y)
		return (1);
	return (0);
}
