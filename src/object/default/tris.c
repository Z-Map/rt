/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 01:59:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/24 17:03:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_tris(t_rtobj *object)
{
	object->data.plan = (struct s_rtplan){.material = NULL};
}
