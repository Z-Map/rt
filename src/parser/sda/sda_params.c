/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:35:04 by ealbert           #+#    #+#             */
/*   Updated: 2017/06/11 17:21:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"
#include "generated/rt_typetab_gen.h"

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

static char			*get_name(char *s)
{
	char			*n;

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

static int			check_line3(t_rtnode *node, t_gparse gparse)
{
	const t_rtobind	*tab = g_obt_tab;
	int				tid;
	t_rtobj			*obj;
	t_rtmat			*mat;

	obj = ((t_rtobi *)(node->content))->obj;
	tid = obj_type_search(obj->type);
	gparse.mem = obj;
	gparse.cfgbits = (char *)&(obj->usercfg);
	if (tab[tid].parse_elm &&
		ft_eparse(gparse, (t_elm *)(t_ul)tab[tid].parse_elm, obj) != -1)
		return (1);
	if (tab[tid].type & (VISIBLE|SCENE))
	{
		mat = ((t_rtobd *)obj)->plan.material;
		gparse.cfgbits = NULL;
		gparse.mem = mat;
		if (mat && (ft_eparse(gparse, (t_elm *)(t_ul)&g_el_mat, mat) != -1))
			return (1);
	}
	return (0);
}

static int			check_line2(t_rtnode *node, char *s)
{
	t_gsep			sep;
	t_gparse		gparse;
	t_rtobi			*obi;

	obi = (t_rtobi *)(node->content);
	sep = (t_gsep){.separator = ":", .end = NULL, .slen = 1, .elen = 0};
	gparse = (t_gparse){.seplst = &sep, .seplen = 1, .end = "\n",
	.cursor = NULL, .c_len = 0, .buffer = s, .b_len = ft_strlen(s),
	.key = NULL, .k_len = 0, .value = NULL, .v_len = 0,
	.arg = NULL, .mem = node->content, .cfgbits = (char *)&(obi->flags)};
	gparse.v_len = gparse.b_len;
	gparse.value = gparse.buffer;
	if (ft_eparse(gparse, (t_elm *)(t_ul)&g_elm_inst, obi) != -1)
		return (1);
	return (check_line3(node, gparse));
}

int					check_line(t_rtnode *node, char *s)
{
	const t_rtobind	*tab = g_obt_tab;
	size_t			len;

	len = RT_OBT_TAB_LEN;
	while (len--)
		if (!ft_strconcur(s, tab[len].name))
			break ;
	if (!ft_strconcur(s, "CUBE"))
		len = obj_type_search(CUBOID);
	if (len < RT_OBT_TAB_LEN)
		return (sda_make_node_parser(node, tab[len].type, get_name(s)));
	else if (node->content)
		return (check_line2(node, s));
	return (0);
}
