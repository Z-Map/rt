#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

//t_point rect_center_pts(mglimg *img, t_point dim)
//{
  //      return ((t_point){.x = img->x / 2 - dim.x / 2, .y = img->y / 2 - dim.y / 2});
//}

void	center_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
	t_v2i pts;

	pts = ((t_v2i){.x = dim_p.x / 2 - dim_c.x / 2, .y = dim_p.y / 2 - dim_c.y / 2});
	pos->x += pts.x;
	pos->y += pts.y;
}

void    top_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
        t_v2i pts;

        pts = ((t_v2i){.x = dim_p.x / 2 - dim_c.x / 2, .y = 0});
        pos->x += pts.x;
        pos->y += pts.y;
}

void    bottom_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
        t_v2i pts;

        pts = ((t_v2i){.x = dim_p.x / 2 - dim_c.x / 2, .y = dim_p.y - dim_c.y});
        pos->x += pts.x;
        pos->y += pts.y;
}

void    left_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
        t_v2i pts;

        pts = ((t_v2i){.x = 0, .y = dim_p.y / 2 - dim_c.y / 2});
        pos->x += pts.x;
        pos->y += pts.y;
}

void    right_pts(t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
        t_v2i pts;

        pts = ((t_v2i){.x = dim_p.x - dim_c.x, .y = dim_p.y / 2 - dim_c.y / 2});
        pos->x += pts.x;
        pos->y += pts.y;
}
