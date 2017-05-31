/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:15:56 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/31 02:40:35 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_rt_rmgr_tree
{
	t_rtnode	*visible;
	t_rtnode	*light;
	int			ldepth;
	int			vdepth;
}				t_rntree;

int			rt_is_visible(void *content)
{
	t_rtobi		*inst;

	if (!content)
		return (0);
	inst = (t_rtobi *)content;
	if (inst->obj->type | VISIBLE)
		return (1);
	return (0);
}

int			rt_is_light(void *content)
{
	t_rtobi		*inst;

	if (!content)
		return (0);
	inst = (t_rtobi *)content;
	if (inst->obj->type | VISIBLE)
		return (1);
	return (0);
}

int			get_visible(t_tree *tree, t_rntree *rntree, int (*f)(void *env))
{
	/* J'arrive pas à coder omg */
}

int			get_light(t_tree *tree, t_rntree *rntree, int (*f)(void *env))
{
   /* J'arrive pas à coder omg² */
}

t_rmgrtree	*make_render_tree(t_rtree *tree)
{
	t_rntree	*rntree;
	int			(*vis)(void *);
	int			(*lgt)(void *);

	if (!tree || !(rntree = (t_rntree *)malloc(sizeof(t_rntree))))
		return (NULL);
	vis = &rt_is_visible;
	lgt = &rt_is_light;
	get_visible(tree, rntree, vis);
	get_light(tree, rntree, lgt);
	if (!(rntree->ldepth) || !(rntree->vdepth))
	{
		if (rntree)
			free(rntree);
		return (NULL);
	}
	return (rntree);
}
