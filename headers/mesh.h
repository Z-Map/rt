/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 17:51:04 by alhote            #+#    #+#             */
/*   Updated: 2016/08/16 17:31:34 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H
# include "t_v4.h"
# include "texture.h"

typedef struct			s_vertex
{
	t_v4d				pos;
	t_v2f				uv;
}						t_vertex;

typedef struct			s_triangle
{
	unsigned int		color;
	t_vertex			v1;
	t_vertex			v2;
	t_vertex			v3;
	t_texture			*texture;
	t_texture			*normal;
}						t_triangle;

typedef struct			s_mesh
{
	char				*filepath;
}						t_mesh;

int						add_mesh_from_obj(t_obj *obj, const char *filepath);
#endif
