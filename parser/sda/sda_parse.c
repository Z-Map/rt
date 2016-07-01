/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 12:54:20 by snicolet          #+#    #+#             */
/*   Updated: 2016/07/01 20:00:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sda.h"
#include "rt.h"
#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <unistd.h>

static t_obj	*sda_parse_error(t_obj *root, char *line)
{
	if (root)
		rt_node_free(root);
	if (line)
		free(line);
	ft_putendl_fd("parse error.", 2);
	return (NULL);
}

static t_obj	*sda_parse_fd(const int fd, t_rt *rt, t_obj *root,
	int lvl_offset)
{
	char		*line;
	int			count;
	int			ret;
	t_sda		eval;

	eval = (t_sda){fd, rt, root, root, 0, lvl_offset};
	count = 0;
	ret = 0;
	while ((ft_get_next_line(fd, &line) > 0) && (line))
	{
		count++;
		if ((ret = sda_eval(line, &eval, sda_lvl(line))) < 0)
		{
			ft_printf("warning: eval failed on line: %d\n", count);
			break ;
		}
		free(line);
	}
	if ((ret < 0) && (root))
		return (sda_parse_error(root, line));
	return (root);
}

t_obj			*sda_parse_rawtree(const char *filepath, t_rt *rt, t_obj *root,
	int lvl_offset)
{
	int		fd;

	if ((fd = open(filepath, O_RDONLY)) < 0)
		return (NULL);
	root = sda_parse_fd(fd, rt, root, lvl_offset);
	close(fd);
	return (root);
}

t_obj			*sda_parse(const char *filepath, t_rt *rt)
{
	t_obj	*old_root;
	t_obj	*root;

	if (!(root = rt_factory_alloc(ROOT, NULL)))
		return (NULL);
	old_root = root;
	root = sda_parse_rawtree(filepath, rt, root, 0);
	if (!root)
		return (NULL);
	yolo_parse_finalize(root);
	sda_set_defaults(root);
	camera_save(rt);
	rt_debug(root, 0);
	if (root->content)
		geo_putm4(((t_obj*)root->content)->trans, 6);
	return (root);
}
