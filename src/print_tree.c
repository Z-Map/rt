/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:59:51 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/15 22:54:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"

typedef struct	s_printree // A mettre dans un .h !
{
	int			run;
	int			tab;
}				t_ptree;

static int		recursive(t_ptree *p, t_rtnode *node, int i)
{
	t_rtobi		*content;
	int			j;

	j = i;
	while (j--)
		ft_putchar('\t');
	ft_printf("NODE: ");
	content = (t_rtobi *)node->content;
	if (content)
	{
		if (content->obj)
			ft_printf(" Obj(type: %X, name: '%s')\n", content->obj->type,
				content->obj->name);
		else
			ft_printf(" Invalid instance\n");
	}
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
	t_ptree		p;
	t_rtnode	*tmp;

	i = -1;
	p.run = 1;
	p.tab = 0;
	if ((tmp = (t_rtnode *)tree))
		recursive(&p, tmp, 0);
	return (1);
}