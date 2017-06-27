/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda_data_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:14:22 by qloubier          #+#    #+#             */
/*   Updated: 2017/05/12 16:25:48 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDA_DATA_PARSER_H
# define SDA_DATA_PARSER_H

# include "rt_prototype.h"
# include "data/rt_data_tree.h"

typedef struct		s_rt_parsenode
{
	t_rtnode		node;
	char			*name;
}					t_pnod;

#endif
