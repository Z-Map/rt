/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_make_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:15:49 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/24 20:21:01 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"


static char			*get_name(char *s)
{
	char			*n;

	if ((n = ft_strchr(s, (int)':')))
		n = ft_strpskp(n + 1, FT_WHITESPACE);
	if (!n || !(*n))
	{
		n = s;
		while (ft_isupper(*s))
		{
			*s = (char)ft_tolower((int)*s);
			s++;
		}
		*s = '\0';
	}
	return (n);
}

int			sda_make_node(t_rtnode *node, t_rtobt type, char *s)
{
	t_rtnode		*new;
	t_rtobi			*inst;
	t_rtobj			*obj;
	char			*name;

	new = NULL;
	inst = NULL;
	obj = NULL;
	name = get_name(s);
	if ((obj = mkobject(type, name)) && (!(type & VISIBLE) ||
		(((t_rtobd *)obj)->plan.material = mkmaterial("default"))) &&
		(inst = mkinstance(obj, NULL)) &&
		(new = mknode(inst)) && tree_addchild(node, new))
		return (1);
	if (obj && (type & VISIBLE))
		rmmaterial(((t_rtobd *)obj)->plan.material);
	if (inst)
		rminstance(inst);
	if (obj)
		rmobject(obj);
	if (new)
		rmnode(&new);
	return (-1);
}
