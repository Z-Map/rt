/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:57:36 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 17:00:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rt_ui.h"
#include <stdlib.h>

t_layer_root	*init_layer_root(t_v2i dim)
{
	t_layer_root *l;

	if (!(l = malloc(sizeof(t_layer_root))))
		return (0);
	l->gen.id = 0;
	l->gen.dim = dim;
	l->gen.pos = (t_v2i){0, 0};
	return (l);
}
