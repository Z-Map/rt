/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:38:42 by lcarreel          #+#    #+#             */
/*   Updated: 2017/07/02 18:45:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"
#include "rt_object.h"
#include "rt_core.h"

static t_v3f	travelling(t_rtobi *cam, t_v3f vec, int k)
{
	if (k == MGLW_KEY_W)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, 0.0, -0.2},
			cam->transform));
	else if (k == MGLW_KEY_S)
		vec = v3faddv3f(vec, mattf_apply((t_v3f){0.0, 0.0, 0.2},
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
	return (vec);
}

t_rt			*rt_keyboard_camera(t_rt *rt, int k)
{
	t_rtobi		*cam;
	t_v3f		vec;

	cam = rt->tree->camera->content;
	if (!rt->tree->camera)
		return (0);
	vec = cam->transform.offset;
	cam->transform.offset = nv3f(0.0f);
	if (k == MGLW_KEY_UP)
		pmattf_rotx(&(cam->transform), 0.1);
	else if (k == MGLW_KEY_DOWN)
		pmattf_rotx(&(cam->transform), -0.1);
	else if (k == MGLW_KEY_LEFT)
		pmattf_rotz(&(cam->transform), 0.1);
	else if (k == MGLW_KEY_RIGHT)
		pmattf_rotz(&(cam->transform), -0.1);
	else if (k == MGLW_KEY_W || k == MGLW_KEY_S || k == MGLW_KEY_A ||
			k == MGLW_KEY_D || k == MGLW_KEY_Q || k == MGLW_KEY_E)
		vec = travelling(cam, vec, k);
	else
		rt = NULL;
	cam->transform.offset = vec;
	return (rt);
}
