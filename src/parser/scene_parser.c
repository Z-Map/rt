/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:17:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/25 17:01:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_rtree			*parse_scene(const char *filename)
{
	const char	*ext;
	t_rtree		*ret;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (NULL);
	ext++;
	ret = NULL;
	if (ft_strequ(ext, "sda"))
		ret = sda_parser(filename);
	return (ret);
}
