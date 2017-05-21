/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:35:04 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/20 13:20:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

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
		tree_addchild(node, new))
		return (1);
	if (obj)
		rmobject(obj);
	if (inst)
		rminstance(inst);
	if (new)
		rmnode(&new);
	return (-1);
}

static int		check_line2(t_rtnode *node, char *s)
{
    (void)s;
    (void)node;
    return (0);
}

int				check_line(t_rtnode *node, char *s)
{
    int         type;
    t_rtobind   index = g_obt_tab;
    t_gsep      sep = {.separator = ":", .end = NULL, .slen = 1, .elen = 0};
    t_gparse    gparse = {.seplst = &sep, .seplen = 1, .end = "\n"
        .cursor = NULL, .c_len = 0, .buffer = s, .b_len = ft_strlen(s)
        .key = NULL, .k_len = 0, .value = line, .v_len = linelen,
        .arg = NULL, .mem = node->content, .cfgbits = &obinst.flags};

    if ((type = obj_typename_search(s)) != -1)
        return (make_new_node(node, index[type].name, s));
    else
    {
        type = obj_typename_search(node->content->name);
    }
    return (check_line2(node, s));
}
