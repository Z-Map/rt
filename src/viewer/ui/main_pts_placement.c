#include "rt_ui.h"
#include "rt_tree.h"
#include <stdio.h>

void	main_pts_placement(int placement, t_v2i *pos, t_v2i dim_p, t_v2i dim_c)
{
	if (PL_MIDDLE == placement)
		center_pts(pos, dim_p, dim_c);
	else if(PL_TOP == placement)
		top_pts(pos, dim_p, dim_c);
	else if(PL_BOTTOM == placement)
		bottom_pts(pos, dim_p, dim_c);
	else if(PL_LEFT == placement)
		left_pts(pos, dim_p, dim_c);
	else if (PL_RIGHT)
		right_pts(pos, dim_p, dim_c);
}
