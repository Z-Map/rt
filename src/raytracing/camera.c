/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:48:07 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 19:31:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_prototype.h"
#include "rt_object.h"
#include "rt_tree.h"

t_rtray		rdr_pxray(t_ui x, t_ui y, t_rtrmgr *rmgr, t_rtrnode *camnode)
{
	t_rtobi	*cam;
	t_rtray	ray;
	double	fov;
	t_v3f	vec;
	t_v3f	vec2;

	cam = (t_rtobi *)(camnode->node.content);
	fov = (fmod(((t_rtobd *)(cam->obj))->camera.fov.x / 180.0, 360.0) * M_PI);
	ray.start = camnode->transform.offset;
	ray.direction = camnode->transform.z;
	vec2 = nv3f(cos(fov / 2));
	pv3fmulv3f(&ray.direction, &vec2);
	// fov = sinf(fov);
	vec = camnode->transform.x;
	vec2 = nv3f((((float)x / (float)(rmgr->rsize.x)) - 0.5f));
	pv3fmulv3f(&vec, &vec2);
	pv3faddv3f(&ray.direction, &vec);
	fov = (double)(rmgr->rsize.y) / (double)(rmgr->rsize.x);
	vec = camnode->transform.y;
	vec2 = nv3f((0.5f - ((float)y / (float)(rmgr->rsize.y))) * (float)fov);
	pv3fmulv3f(&vec, &vec2);
	pv3faddv3f(&ray.direction, &vec);
	ray.direction = normalize3f(ray.direction);
	return (ray);
}
