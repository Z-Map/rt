/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:35:04 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/09 16:39:46 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_object.h"
#include "data_sda.h"

/*
** make_new_node :
** crée une node en fonction du type d'objet trouvé dans le sda.
** il y ajoute une instance.
**
** check_line et check_line2 :
** Désolé pour la forêt d'if.
** Check si la ligne correspond à quelque chose de connu.
** Si le mot est inconnu au parser, on appellera une fonction d'erreur.
*/

static char		*get_name(char *s)
{
	char		*n;

	if ((n = ft_strchr(s, (int)':')))
		n = ft_strpskp(n, FT_WHITESPACE);
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

static int		make_new_node(t_rtnode *node, t_rtobt type, char *s)
{
	t_rtnode	*new;
	t_rtobi		*inst;
	t_rtobj		*obj;
	char		*name;

	new = NULL;
	inst = NULL;
	obj = NULL;
	name = get_name(s);
	if ((obj = mkobject(type, name)) &&
		(inst = mkinstance(obj, NULL)) &&
		(new = mknode(inst)) &&
		(new = tree_addchild(node, new)))
		return (1);
	if (obj)
		rmobject(obj);
	if (inst)
		rminstance(inst);
	if (new)
		rmnode(new);
	return (-1);
}

static int		check_line2(t_rtnode *node, char *s)
{
	(void)node;
	(void)s;
	return (0);
}

int				check_line(t_rtnode *node, char *s)
{
	if (!ft_strncmp(s, "EMPTY", 5))
		return (make_new_node(node, EMPTY, s));
	else if (!ft_strncmp(s, "CAMERA", 6))
		return (make_new_node(node, CAMERA, s));
	else if (!ft_strncmp(s, "PLAN", 4))
		return (make_new_node(node, PLAN, s));
	else if (!ft_strncmp(s, "SPHERE", 6))
		return (make_new_node(node, SPHERE, s));
	else if (!ft_strncmp(s, "CONE", 4))
		return (make_new_node(node, CONE, s));
	else if (!ft_strncmp(s, "CYLINDER", 8))
		return (make_new_node(node, CYLINDER, s));
	else if (!ft_strncmp(s, "CUBOID", 6))
		return (make_new_node(node, CUBOID, s));
	else if (!ft_strncmp(s, "MESH", 4))
		return (make_new_node(node, MESH, s));
	else if (!ft_strncmp(s, "TRIS", 3))
		return (make_new_node(node, TRIS, s));
	else if (!ft_strncmp(s, "SPOT", 4))
		return (make_new_node(node, SPOT, s));
	else if (!ft_strncmp(s, "POINTLIGHT", 10))
		return (make_new_node(node, POINTLIGHT, s));
	else if (!ft_strncmp(s, "SUNLIGHT", 8))
		return (make_new_node(node, SUNLIGHT, s));
	return (check_line2(node, s));
}
