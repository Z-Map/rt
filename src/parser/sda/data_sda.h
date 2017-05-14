/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sda.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:39:03 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/09 18:07:06 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SDA_H

# define DATA_SDA_H

# include "rt_tree.h"

typedef struct		s_sda_env
{
	int				fd;
	int				ret;
	char			*line;
	int				tab;
	int				move;
	t_rtnode		*curr;
}					t_sda_env;

int         	    check_line(t_rtnode *node, char *s);

#endif
