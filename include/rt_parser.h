/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/21 04:42:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# include "mathex/matrix.h"
# include "mathex/vector.h"
# include "rt_prototype.h"
# include "rt_core.h"
# include "rt_object.h"
# include "data/data_obj.h"
# include "data/data_matrix_parse.h"
# include "data/data_sda.h"

int			rt_parse_args(t_rt *rt, int ac, char **av);
int			arg_commandmode(const char *arg, void *env,
		const char **nextargtab, int tab_len);
int			arg_fileout(const char *arg, void *env,
		const char **nextargtab, int tab_len);
int			arg_clientmode(const char *arg, void *env,
		const char **nextargtab, int tab_len);
int			arg_visualprev(const char *arg, void *env,
		const char **nextargtab, int tab_len);
int			arg_modes(const char *arg, void *env,
		const char **nextargtab, int tab_len);

int			rt_parser_obj(char *file, t_obj *obj);
int			check_line(t_rtnode *node, char *s);
t_rtree		*sda_parser(const char *s);

#endif
