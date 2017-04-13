/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_mkinstance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:37:42 by ealbert           #+#    #+#             */
/*   Updated: 2017/04/13 23:47:56 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data/rt_data_objects.h"

/*
** Creer une instance selon Eddy.
** Je n'ai encore vu comment marchaient exactement tes blocklists, mais ca m'a
** l'air pratique. Du coup je me suis dit que j'allais l'utiliser pour le parser
** de fichiers sda.
**
** Pour ce qui est de mkinstance :
**
** On check si name et id sont bien valides.
** On malloc une nouvelle instance. Puis l'on assigne les valeurs en parametres
** aux variables correspondantes.
** On met la structure de l'objet a NULL (pour l'instant pour gerer les cas ou
** l'objet trouve doit etre gere autrement (ex: EMPTY/SETTING)
**
** Cette fonction serait appelee quand on trouve un nouvel objet (ex:"PLAN")
** et suivi de mkobject si le nom trouve est un objet materiel.
** Par exemple, si l'on trouve "SETTING", pas besoin de malloc de la place pour
** l'objet.
*/

t_rtobi		sda_mkinstance(char *name, unsigned int id, int flags)
{
	t_rtobi		new;

	if (!name || !id)
		return (NULL);
	if (!new = (t_rtobi)malloc(sizeof(t_rtobi)))
		return (NULL);
	if (!(new.name = ft_strdup(name)))
		return (NULL);
	new.id = id;
	new.flags = flags;
	new.data = NULL;
	return (new);
}
