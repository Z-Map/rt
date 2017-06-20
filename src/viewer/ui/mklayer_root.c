/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklayer_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:00:27 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 20:00:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rt_ui.h"
#include <stdlib.h>

t_layer_root		*mklayer_root(t_v2i dim)
{
	t_layer_root	*l;

	if (!(l = malloc(sizeof(t_layer_root))))
		return (0);
	l->gen.id = 0;
	l->gen.dim = dim;
	l->gen.pos = (t_v2i){0, 0};
	return (l);
}
