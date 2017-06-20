#ifndef RT_UI_DISPLAY_H
# define RT_UI_DISPLAY_H

# include "rt_ui.h"
# include "rt_prototype.h"
# include "mglw/mglw.h"

void	draw_rect(mglimg *img, t_layer_rect *rect);

int	add_rgb_in_img(mglimg *img, unsigned int index, t_v4i color);

#endif
