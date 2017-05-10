/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:59:51 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/10 18:03:00 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"
#include "libft.h"

typedef struct	s_printree
{
	int			run;
	int			tab;
}				t_ptree;

static int	recursive(t_ptree *p, t_rtnode *tmp, int i)
{
	i = -1;
	while (++i < tab)
		ft_printf("%c", '\t');
	ft_printf("NODE: type: %X | name: '%s'\n", node->content->obj.type,
		node->content->objs->name);
	if (tmp->childs)
	{
		tab++;
		recursive(p, tmp->childs, i);
	}
	if (tmp->next)
		recursive(p, tmp->next, i);
	tab--;
	return (1);
}

int			print_tree(t_rtree *tree)
{
	int			i;
	t_ptree		p;
	t_rtnode	*tmp;

	p.run = 1;
	p.tab = 0;
	tmp = &(tree->node);
	recursive(p, tmp, i);
	return (1);
}
