#include "rt_ui_display.h"
#include "mathex/vector.h"

int	is_border(t_layer_border *b, int x, int y)
{
	int vx;
	int vy;

	vx = b->dim_border * b->gen.dim.x;
	vy = b->dim_border * b->gen.dim.y;
	//top test
	if (y < vy && (b->valid_border & 1))
		return (1);
	//left test
	if (x < vx && (b->valid_border & 2))
		return (1);
	//right
	if (x >= b->gen.dim.x - vx && (b->valid_border & 4))
		return (1);
	//bottom test
	if (y >= b->gen.dim.y - vy && (b->valid_border & 8))
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
