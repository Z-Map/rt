#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

t_layer_label	*mklayer_label(t_v2f pos, t_v2f dim, t_v4i color,\
	int placement)
{
	t_layer_label	*label;

	if (!(label = malloc(sizeof(t_layer_label))))
		return (0);
	label->pos = (t_v2f){pos.x, pos.y};
	label->dim = (t_v2f){dim.x, dim.y};
	label->color = (t_v4i){color.x, color.y, color.z, color.w};
	label->gen.placement = placement;
	label->gen.show = 1;
	label->gen.event = 0;
	return (label);
}

void		layer_label_add(t_layer_label *label, char *str)
{
	label->label = str;
}

t_rtnode	*mknlayer_label(t_v2f pos, t_v2f dim, t_v4i color,\
	int placement)
{
        t_layer_label	*label;
        t_rtnode	*node;

	if (!(label = mklayer_label(pos, dim, color, placement)))
		return (0);
	node = mknode((t_rtobi *)(label));
	node->type = TE_LABEL;
	node->flags = get_id_ui_node();
	return (node);
}
