/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:59:51 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/11 14:23:02 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_tree.h"
#include "libft.h"

typedef struct	s_printree
{
	int			run;
	int			tab;
}				t_ptree;

static int		recursive(t_ptree *p, t_rtnode *node, int i)
{
	t_rtobi		*content;

	content = (t_rtobi *)node->content;
	i = -1;
	while (++i < p->tab)
		ft_printf("%c", '\t');
	ft_printf("NODE: type: %X | name: '%s'\n", content->obj->type,
		content->obj->name);
	if (node->childs)
	{
		p->tab++;
		recursive(p, node->childs, i);
	}
	if (node->next)
		recursive(p, node->next, i);
	p->tab--;
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
	tmp = &(tree->node);
	recursive(&p, tmp, i);
	return (1);
}
