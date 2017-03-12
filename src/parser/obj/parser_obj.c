/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:04:07 by lcarreel          #+#    #+#             */
/*   Updated: 2017/03/12 17:22:00 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "rt_parser.h"

static int	init_blst(t_obj *obj)
{
	if ((obj->parser = (t_objpars *)malloc(sizeof(t_objpars))) == NULL)
		return (2);
	obj->parser->v_blst = ft_blstnew(sizeof(t_v3f), 1024);
	obj->parser->vn_blst = ft_blstnew(sizeof(t_v3f), 1024);
	obj->parser->uv_blst = ft_blstnew(sizeof(t_v2f), 1024);
	obj->parser->fv_blst = ft_blstnew(sizeof(t_v3ui), 1024);
	obj->parser->fuv_blst = ft_blstnew(sizeof(t_v3ui), 1024);
	obj->parser->fvn_blst = ft_blstnew(sizeof(t_v3ui), 1024);
	obj->vertices = NULL;
	obj->normales = NULL;
	obj->uv = NULL;
	return (0);
}

static int	parse_face(char *line, t_obj *obj)
{
	t_v3i	tmp_fv;
	t_v3i	tmp_fuv;
	t_v3i	tmp_fvn;

	tmp_fv = (t_v3i){0, 0, 0};
	tmp_fuv = (t_v3i){0, 0, 0};
	tmp_fvn = (t_v3i){0, 0, 0};

	line++;
	if (!(*line && (ft_sscanf(line, "%d/%_d/%_d",
					&tmp_fv.x, &tmp_fuv.x, &tmp_fvn.x) > 0)))
		return (1);
	line = ft_strchrnul(line + 2, (int)' ');
	if (!(*line && ft_sscanf(line, "%d/%_d/%_d",
				&tmp_fv.y, &tmp_fuv.y, &tmp_fvn.y) > 0))
		return (1);
	line = ft_strchrnul(line + 1, (int)' ');
	if (!(*line && ft_sscanf(line, "%d/%_d/%_d",
				&tmp_fv.z, &tmp_fuv.z, &tmp_fvn.z) > 0))
		return (1);
	ft_blststore(obj->parser->fv_blst, &tmp_fv);
	ft_blststore(obj->parser->fuv_blst, &tmp_fuv);
	ft_blststore(obj->parser->fvn_blst, &tmp_fvn);
	return (0);
}

static int	fill_tabs(t_obj *obj)
{
	obj->vertices = ft_blsttotab(obj->parser->v_blst, &obj->v_len);
	obj->normales = (obj->vn_len == 0) ? NULL :
		ft_blsttotab(obj->parser->vn_blst, &obj->vn_len);
	obj->uv = (obj->uv_len == 0) ? NULL :
		ft_blsttotab(obj->parser->uv_blst, &obj->uv_len);
	obj->f_vertices = ft_blsttotab(obj->parser->fv_blst, &obj->fv_len);
	obj->f_uv = ft_blsttotab(obj->parser->fuv_blst, &obj->fuv_len);
	obj->f_normales = ft_blsttotab(obj->parser->fvn_blst, &obj->fvn_len);
	return (0);
}

static int	parse_file(int fd, t_obj *obj)
{
	int		ret;
	t_v3f	tmp;
	t_v2f	tmp_uv;
	char	*line;

	init_blst(obj);
	while ((ret = ft_get_line(fd, &line)) && ret != -1)
	{
		if (ft_sscanf(line, "v %f %f %f", &tmp.x, &tmp.y, &tmp.z) == 3)
			ft_blststore(obj->parser->v_blst, &tmp);
		else if (ft_sscanf(line, "vn %f %f %f", &tmp.x, &tmp.y, &tmp.z) == 3)
			ft_blststore(obj->parser->vn_blst, &tmp);
		else if (ft_sscanf(line, "vt %f %f", &tmp_uv.x, &tmp_uv.y) == 2)
			ft_blststore(obj->parser->uv_blst, &tmp_uv);
		else if (*line == 'f')
			parse_face(line, obj);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	fill_tabs(obj);
	return (0);
}

int			rt_parser_obj(char *file, t_obj *obj)
{
	int		fd;
	size_t	i;

	i = -1;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	parse_file(fd, obj);
	return (0);
}
