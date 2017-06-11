/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:17:58 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 22:45:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"
#include "rt_parser.h"

static t_rtobj	*get_scene(t_rtree *tree)
{
	t_ui		arg[3];
	t_rtnode	*nd;

	arg[0] = RT_GET;
	arg[1] = (t_ui)SCENE;
	arg[2] = 0;
	nd = tree_find((t_rtnode *)tree,
		(int (*)(void *, void *))&node_isoftype, arg);
	if (nd || ((nd = make_node(SCENE, "params"))
		&& tree_addchild((t_rtnode *)tree, nd)))
		return (nd->content->obj);
	return (NULL);
}

static t_rtree	*validate_tree(t_rtree *tree)
{
	find_camera(tree);
	if (!(tree->camera) || !(tree->scene = get_scene(tree)))
		rmrtree(&tree);
	return (tree);
}

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
	if (ret)
		ret = validate_tree(ret);
	return (ret);
}
