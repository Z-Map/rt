#ifndef RT_UI_H
# define RT_UI_H

# include "data/data_ui.h"

int		get_id_ui_node(void);

t_rtnode	*init_ui(t_v2i dim);

t_layer_root	*mklayer_root(t_v2i dim);

t_layer_rect	*mklayer_rect(t_v2f pos, t_v2f dim, t_v4i color, int placement);

#endif
