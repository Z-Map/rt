/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:28:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 00:50:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_rt	rt_root;

	if (rt_init_main(&rt_root)
		&& rt_parse_args(&rt_root, argc - 1, argv + 1))
		rt_main(&rt_root);
	return (rt_quit(&rt_root));
}
