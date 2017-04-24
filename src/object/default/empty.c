/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:23:47 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 02:23:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"

void			object_default_empty(t_rtobj *object)
{
	object->data.empty = (struct s_rtempty){
		.subtree = NULL, .size = 1.0};
}
