/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:50:08 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/12 15:43:38 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "data/data_sda.h"

/*
** tab_diff :
** tab diff donne la difference de tab entre la ligne precedente et la ligne
** actuelle. Si la ligne actuelle a plus d'un tab en plus sur la ligne
** precedente, la fonction renvoie une erreur.
** Si tab diff renvoie un nombre negatif, on remonte dans l'arborescence.
** Si tab diff renvoie 0, on reste dans la node courante.
** Si tab diff renvoie 1, on descend dans l'arborescence.
**
** move node :
** permet de changer de node en fonction de ce que tab_diff renvoie.
**
** read_file :
** Effectue la lecture du fichier, et execute les fonctions pour chaque ligne
** lue. La ligne est ensuite effacee avec free.
**
** env_init :
** initialise la structure du parser sda. Tout simplement.
**
** sda_parser :
** Un peu comme le main du parser, il initialise le debut du parser, et renvoie
** ce qu'il y a à renvoyer : un arbre alloué, propre, valide et fonctionnel.
*/

static int			tab_diff(int *tab, char *s)
{
	int		i;
	int		ret;

	i = 0;
	if (!s)
		return (2);
	while (s[i] == '\t')
		i++;
	ret = i - *tab;
	*tab = i;
	return (ret);
}

static void			move_node(int n, t_rtnode **node)
{
	if (n == 1)
	{
		*node = (*node)->childs;
		while ((*node)->next)
			*node = (*node)->next;
	}
	else if (n < 0)
	{
		while (n != 0)
		{
			*node = (*node)->parent;
			n++;
		}
	}
}

static t_rtree		*read_file(t_sda_env *env, t_rtree *tree)
{
	int		i;
	int		ret;

	while ((ret = ft_get_line(env->fd, &(env->line))))
	{
		i = 0;
		env->move = tab_diff(&(env->tab), env->line);
		if (env->move > 1)
			return (ft_mfree_ret(tree, 1, &(env->line))); /* a changer */
		move_node(env->move, &(env->curr));
		while (env->line[i] == '\t')
			i++;
		if (check_line(env->curr, &(env->line[i])) < 0)
			break;
		ft_memdel((void **)&(env->line));
	}
	if (env->line)
		ft_memdel((void **)&(env->line));
	return (tree);
}

static int		env_init(char *s, t_sda_env *env)
{
	if ((env->fd = open(s, O_RDONLY)) == -1)
		return (-1); /* a changer */
	env->move = 0;
	env->tab = 0;
	env->curr = NULL;
	env->line = NULL;
	return (1);
}

t_rtree				*sda_parser(char *s)
{
	t_rtree			*tree;
	t_sda_env		*env;

	if (!(env = (t_sda_env *)malloc(sizeof(t_sda_env))))
		return (NULL); /* a changer */
	if (!(tree = mktree(0)))
		return (NULL); /* a changer */
	env_init(s, env);
	env->curr = &(tree->node);
	return (read_file(env, tree));
}
