/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_mkobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:22:10 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/09 16:34:00 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data/rt_data_objects.h"

/*
** /!\ Cette fonction est incomplete. /!\
** Je ne sais pas encore comment renseigner quelle structure choisir dans
** l'union "u_rt_objectdata"(t_rtobd).
**
** Je pense que les objets seront remplis au fur et a mesure de la lecture.
** Du coup cette fonction ne fera que malloc la structure et donner un nom et
** un flag, ainsi que mettre des valeurs par defaut aux valeurs non renseignees.
**
** Quentin :
** J'ai vite fait regarde t_rtobt. Seems nice. Cela dit je ne sais pas du tout
** pourquoi ta variable s'appelle "type:32". Ca a pas de sens pour moi pour
** l'instant.
**
** Pour l'explication de la fonction :
**
** On check si les elements sont valides.
** On malloc la structure.
** On attribue les valeurs aux variables correspondantes.
** On assigne des valeurs par defaut a chaque variablenon renseignee.*
** *De ce fait, plus besoin de retourner dans l'objet mettre des valeurs par
** defaut a tel ou tel variable, which is nice. (A FAIRE)
** On retourne la structure.
*/
/*
t_rtobj			sda_mkobject(char *name, unsigned int flags *variable pour l'union*)
{
	t_rtobj		new;

	if (!type || !name)
		return (NULL);
	if (!(new = (t_rtobj)malloc(sizeof(t_rtobj))))
		return (NULL);
	if (!(new.name = ft_strdup(name)))
		return (NULL);
	new.flags = flags;
	return (new);
} */
