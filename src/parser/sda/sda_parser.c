/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 01:03:40 by qloubier          #+#    #+#             */
/*   Updated: 2017/07/03 01:03:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "rt_parser.h"

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

static int			move_node(int n, t_rtnode **node)
{
	if ((n == 1) && (*node)->childs)
	{
		*node = (*node)->childs;
	}
	else if (n >= 1)
		return (0);
	else if (n < 0)
	{
		while (n != 0)
		{
			*node = (*node)->parent;
			n++;
		}
	}
	return (1);
}

static t_rtree		*read_file(t_sda_env *env, t_rtree *tree)
{
	int		i;
	int		j;
	int		ret;

	j = 1;
	while ((ret = ft_get_line(env->fd, &(env->line))))
	{
		i = 0;
		env->move = tab_diff(&(env->tab), env->line);
		if (!move_node(env->move, &(env->curr)))
			return (ft_mfree_ret(tree, 1, &(env->line)));
		while (env->line[i] == '\t')
			i++;
		if (check_line(env->curr, &(env->line[i])) < 0)
			break ;
		ft_memdel((void **)&(env->line));
		j++;
	}
	if (env->line)
		ft_memdel((void **)&(env->line));
	return (tree);
}

static t_rtree		*env_init(const char *s, t_sda_env *env)
{
	if ((env->fd = open(s, O_RDONLY)) < 0)
		return (NULL);
	env->move = 0;
	env->tab = 0;
	env->line = NULL;
	if (!(env->curr = (t_rtnode *)mktree(0)))
		return (NULL);
	return ((t_rtree *)env->curr);
}

t_rtree				*sda_parser(const char *s)
{
	t_rtree			*tree;
	t_sda_env		env;

	if ((tree = env_init(s, &env)))
	{
		tree = read_file(&env, tree);
		close(env.fd);
	}
	return (tree);
}
