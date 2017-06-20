/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:41:46 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/20 17:41:54 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_ui.h"
#include "rt_tree.h"
#include <stdlib.h>
#include <stdio.h>

t_rtnode		*init_ui()
{
	t_rtnode	*root;
	int test = 1;

	if (!(root = malloc(sizeof(t_rtnode))))
		return (0);
	root->parent = 0;
	root->next = 0;
	root->childs = 0;
	root->type = TE_ROOT;
	root->flags = 0;
	root->content = (t_rtobi *)(&test);
	printf("---> %d\n", *((int *)(root->content)));
	return (root);
}
