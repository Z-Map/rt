/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:35:04 by ealbert           #+#    #+#             */
/*   Updated: 2017/04/28 18:29:46 by ealbert          ###   ########.fr       */
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

static char	*get_name(char *s)
{

}

static int	make_new_node(t_rtnode *node, t_rtobt type, char *s)
{
	t_rtnode	*new;
	t_rtobi		*inst;
	t_rtobj		*obj;
	char		*name;

	name = get_name(s);
	if (!(obj = mkobject(type, name)))
		return (-1);
	if (!(inst = mkinstance(obj, NULL)))
		return (-1);
	if (!(new = mknode(inst)))
		return (-1);
	if (!(new = tree_addchild(node, new)))
		return (-1);
	return (1);
}

static int	check_line2(t_rtnode *node, char *s)
{

}

int			check_line(t_rtnode *node, char *s)
{
	if (!ft_strcmp(s, "EMPTY"))
		return (make_new_node(node, EMPTY, s));
	else if (!ft_strcmp(s, "CAMERA"))
		return (make_new_node(node, CAMERA, s));
	else if (!ft_strcmp(s, "PLAN"))
		return (make_new_node(node, PLAN, s));
	else if (!ft_strcmp(s, "SPHERE"))
		return (make_new_node(node, SPHERE, s));
	else if (!ft_strcmp(s, "CONE"))
		return (make_new_node(node, CONE, s));
	else if (!ft_strcmp(s, "CYLINDER"))
		return (make_new_node(node, CYLINDER, s));
	else if (!ft_strcmp(s, "CUBOID"))
		return (make_new_node(node, CUBOID, s));
	else if (!ft_strcmp(s, "MESH"))
		return (make_new_node(node, MESH, s));
	else if (!ft_strcmp(s, "TRIS"))
		return (make_new_node(node, TRIS, s));
	else if (!ft_strcmp(s, "SPOT"))
		return (make_new_node(node, SPOT, s));
	else if (!ft_strcmp(s, "POINTLIGHT"))
		return (make_new_node(node, POINTLIGHT, s));
	else if (!ft_strcmp(s, "SUNLIGHT"))
		return (make_new_node(node, SUNLIGHT, s));
//	return (check_line2(node, s));
}
