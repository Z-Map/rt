/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 02:48:07 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/17 16:38:46 by qloubier         ###   ########.fr       */
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

	cam = (t_rtobi *)(camnode->node.content);
	fov = (fmod(((t_rtobd *)(cam->obj))->camera.fov.x / 180.0, 360.0) * M_PI);
	ray.start = camnode->transform.offset;
	ray.direction = camnode->transform.z;
	pv3fmulv3f(&ray.direction, nv3f(-cos(fov / 2)));
	// fov = sinf(fov);
	pv3faddv3f(&ray.direction, v3fmulv3f(camnode->transform.x,
		nv3f((((float)x / (float)(rmgr->rsize.x))) - 0.5f )));
	fov = (double)(rmgr->rsize.y) / (double)(rmgr->rsize.x);
	pv3faddv3f(&ray.direction, v3fmulv3f(camnode->transform.y,
		nv3f((0.5f - ((float)y / (float)(rmgr->rsize.y))) * (float)fov)));
	normalize3f(&ray.direction);
	return (ray);
}
