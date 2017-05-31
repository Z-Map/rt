#include "rt_core.h"

void		rt_resize(void *env, int x, int y)
{
	t_rt	*rt;

	if (!env)
		return ;
	rt = (t_rt *)env;
	rt->render.target_size = (t_v2ui){x, y};
	rt->flags |= RTF_RDRREFRESH;
}
