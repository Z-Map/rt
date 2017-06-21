#include "rt_ui_display.h"
#include "mathex/vector.h"

int	is_border(t_layer_border *b, int x, int y)
{
	//top test
	if (y < b->dim_border)
		return (1);
	//left test
	if (x < b->dim_border)
		return (1);
	//right
	if (x > b->gen.dim.x - b->dim_border)
		return (1);
	//bottom test
	if (y > b->gen.dim.y - b->dim_border)
		return (1);
	return (0);
}

void	draw_border(mglimg *img, t_layer_border *grid)
{
	int cx;
	int cy;
	unsigned int index;

	cx = 0;
	cy = 0;
	while (cy < grid->gen.dim.y)
	{
		while (cx < grid->gen.dim.x)
		{
			if (is_border(grid, cx, cy))
			{
				index = img->x * (grid->gen.pos.y + cy) * 4 +\
				(grid->gen.pos.x + cx) * 4;
				add_rgb_in_img(img, index, grid->color);
			}
			cx++;
		}
		cy++;
		cx = 0;
	}
}
