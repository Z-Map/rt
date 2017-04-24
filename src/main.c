/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:28:23 by qloubier          #+#    #+#             */
/*   Updated: 2017/04/22 22:44:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int			main(int argc, char** argv)
{
	t_rt	rt_root;

	rt_init_main(&rt_root);
	if (!rt_parse_args(&rt_root, argc, argv))
		return (-1);
	rt_main(&rt_root);
	return (rt_quit(&rt_root));
}
