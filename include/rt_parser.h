/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 17:22:02 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# include "rt_prototype.h"
# include "rt_core.h"
# include "data/data_obj.h"

int			rt_parse_args(t_rt *rt, int ac, char **av);
int			rt_parser_obj(char *file, t_obj *obj);

#endif
