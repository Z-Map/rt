/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:56:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/22 20:03:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tools.h"

t_rtray			ray_trans(t_rtray ray, t_mattf m)
{
	v3faddv3f(ray.start, m.offset);
	m.offset = nv3f(0.0f);
	pmattf_apply(&ray.direction, &m);
	return (ray);
}
