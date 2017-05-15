/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/15 18:20:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# include "rt_prototype.h"
# include "rt_core.h"
# include "data/data_obj.h"
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
t_rtree		*sda_parser(const char *s);

#endif
