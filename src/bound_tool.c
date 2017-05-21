/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 03:57:49 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/21 04:07:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/utils.h"
#include "rt_tools.h"

t_mat3x2f			no_bound(void)
{
	return ((t_mat3x2f){.x = {INFINITY, -INFINITY},
		.y = {INFINITY, -INFINITY}, .z = {INFINITY, -INFINITY}});
}
