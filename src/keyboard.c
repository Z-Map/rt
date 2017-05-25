/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:23:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 21:44:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw/mglw.h"
#include "rt_tree.h"
#include "rt_object.h"
#include "rt_core.h"

int			rt_keypress(void *env, int k)
{
	t_rt	*rt;
	t_rtobi	*cam;
	t_v3f	vec;

	rt = (t_rt *)env;
	if (!rt->tree->camera)
		return (0);
	cam = rt->tree->camera->content;
	vec = cam->transform.offset;
	cam->transform.offset = nv3f(0.0f);
	if (k == MGLW_KEY_UP)
		pmattf_rotx(&(cam->transform), 0.1);
	else if (k == MGLW_KEY_DOWN)
		pmattf_rotx(&(cam->transform), -0.1);
	else if (k == MGLW_KEY_LEFT)
		pmattf_rotz(&(cam->transform), -0.1);
	else if (k == MGLW_KEY_RIGHT)
		pmattf_rotz(&(cam->transform), 0.1);
	else if (k == MGLW_KEY_W)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, 0.0, 0.2},
			cam->transform));
	else if (k == MGLW_KEY_S)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, 0.0, -0.2},
			cam->transform));
	else if (k == MGLW_KEY_A)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){-0.2, 0.0, 0.0},
			cam->transform));
	else if (k == MGLW_KEY_D)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.2, 0.0, 0.0},
			cam->transform));
	else if (k == MGLW_KEY_Q)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, 0.2, 0.0},
			cam->transform));
	else if (k == MGLW_KEY_E)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, -0.2, 0.0},
			cam->transform));
	else
		rt = NULL;
	if (rt)
		rt->flags |= RTF_RDRREFRESH;
	cam->transform.offset = vec;
	return (0);
}
