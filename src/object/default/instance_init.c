/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:45:32 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/24 17:01:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			obinst_default(t_rtobi *inst, t_rtobj *obj, const char *name)
{
	static t_ui	id = 0;

	*inst = (t_rtobi){ .id = id++, .flags = 0, .name = ft_vsdup(name),
		.transform = mattf_identity(), .obdata = obj};
}
