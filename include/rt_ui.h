#ifndef RT_UI_H
# define RT_UI_H

# include "data/data_ui.h"

t_rtnode	*init_ui(void);

t_layer_root	*init_layer_root(t_v2i dim);

t_layer_rect	*init_layer_rect(t_v2f pos, t_v2f dim, t_v4i color, int placement);

#endif
