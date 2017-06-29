/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:23:36 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 20:24:00 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>

/*
** ajout du free du label et du term : to do
*/

static void		free_node(t_rtnode *node)
{
	if (node->type == TE_TERM || node->type == TE_LABEL)
	{
	}
	if (node->content)
		free(node->content);
	if (node)
		free(node);
}

static void		del_all(t_rtnode *node)
{
	t_rtnode	*tmp;

	tmp = node;
	if (tmp->next)
		del_all(node->next);
	if (tmp->childs)
		del_all(node->childs);
	free_node(tmp);
}

void			delui(t_rtnode *node)
{
	del_all(node);
}
