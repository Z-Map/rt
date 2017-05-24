/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_make_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:15:49 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/24 21:51:58 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int			sda_make_node(t_rtnode *node, t_rtobt type, const char *name)
{
	t_rtnode		*new;
	t_rtobi			*inst;
	t_rtobj			*obj;

	new = NULL;
	inst = NULL;
	obj = NULL;
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
