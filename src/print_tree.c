/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:59:51 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/20 14:43:35 by qloubier         ###   ########.fr       */
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
	if (obj->type & VISIBLE)
	{
		while (j--)
			ft_putchar('\t');
		m = obi->lbounds;
		m = *((t_mat3x2f *)(t_ul)&(((t_rtobd *)obj)->plan.limx));
		ft_printf("bounds : x[%v2f] y[%v2f] z[%v2f]}\n", &m.x, &m.y, &m.z);
	}
	return (1);
}

static int		recursive(t_v2i *p, t_rtnode *node, int i)
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
		recursive(p, node->childs, i + 1);
	if (node->next)
		recursive(p, node->next, i);
	return (1);
}

int			print_tree(t_rtree *tree)
{
	int			i;
	t_v2i		p;
	t_rtnode	*tmp;

	i = -1;
	p.x = 1;
	p.y = 0;
	if ((tmp = (t_rtnode *)tree))
		recursive(&p, tmp, 0);
	return (1);
}
