/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:59:51 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/26 14:46:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

static int		print_node(t_rtobi *obi, int i)
{
	t_rtobj		*obj;
	int			j;
	t_mat3x2f	m;

	obj = (t_rtobj *)obi->obj;
	if (!obj)
		return ((int)ft_printf(" Invalid instance\n"));
	ft_printf(" Obi{ name: '%s', prop: %b\n", obi->name, obi->flags);
	j = i;
	while (j--)
		ft_putchar('\t');
	ft_printf(" '%s' : Obj(type: %X, prop: %b)\n", obj->name, obj->type,
		obj->usercfg);
	j = i;
	while (j--)
		ft_putchar('\t');
	m = obi->bounds;
	ft_printf("bounds : x[%f,%f] y[%f,%f] z[%f,%f]}\n", m.x.x, m.x.y, m.y.x,
		m.y.y, m.z.x, m.z.y);
	return (1);
}

static int		recursive(t_rtnode *node, int i)
{
	t_rtobi		*content;
	int			j;

	j = i;
	while (j--)
		ft_putchar('\t');
	ft_printf("NODE: ");
	content = (t_rtobi *)node->content;
	if (content)
		print_node(content, i);
	else
		ft_printf("ROOT\n");
	if (node->childs)
		recursive(node->childs, i + 1);
	if (node->next)
		recursive(node->next, i);
	return (1);
}

int			print_tree(t_rtree *tree)
{
	t_rtnode	*tmp;

	if ((tmp = (t_rtnode *)tree))
		recursive(tmp, 0);
	return (1);
}
