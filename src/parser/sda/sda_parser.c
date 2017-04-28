/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:50:08 by ealbert           #+#    #+#             */
/*   Updated: 2017/04/26 17:57:34 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sda.h"

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
	ret = i - tab;
	*tab = i;
	return (ret);
}

static void			move_node(int n, t_rtnode *node)
{
	if (n == 1)
		node = node->childs;
	else if (n == 0)
		;
	else
	{
		while (n != 0)
		{
			node = node->parent;
			n--;
		}
	}
}

static t_rtree		*read_file(t_sda_env *env, t_rtree *tree)
{
	int		i;

	while ((ret = get_next_line(fd, &line)))
	{
		i = 0;
		move = tab_diff(&(env->tab), line);
		if (move > 1)
			return (NULL);/* a changer */
		move_node(move, env->node);
		while (line[i] == '\t')
			i++;
		check_line(node, &line[i]);
	}
}

static void			env_init(t_sda_env *env)
{
	if ((fd = open(s, O_RDONLY)) == -1)
		return (NULL);/* a changer */
	env->move = 0;
	env->tab = 0;
}

t_rtree				*sda_parser(char *s)
{
	t_rtree			*tree;
	t_sda_env		*env;

	if (!(env = (t_sda_env *)malloc(sizeof(t_sda_env))))
		return (NULL);/* a changer */
	if (!(tree = mktree(0)))
		return (NULL);/* a changer */
	env_init(env);
	env->tmp = &(tree->node);
	return (read_file(env, tree));
}
