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

static int	make_new_node(/**/)
{
	t_rtnode	*new;
	t_rtobi		*inst;


	new = mknode(inst);
}

int			check_line(t_rtnode *node, char *s)
{
	if (!ft_strncmp(line, "EMPTY"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "CAMERA"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "PLAN"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "SPHERE"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "CONE"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "CYLINDER"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "CUBOID"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "MESH"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "TRIS"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "SPOT"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "POINTLIGHT"))
		return (make_new_node(node));
	else if (!ft_strncmp(line, "SUNLIGHT"))
		return (make_new_node());
	return (check_line2(node, s, i));
}
