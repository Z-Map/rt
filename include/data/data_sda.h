/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sda.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:39:03 by ealbert           #+#    #+#             */
/*   Updated: 2017/05/15 18:53:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SDA_H

# define DATA_SDA_H

# include "rt_tree.h"

typedef struct		s_sda_env
{
	int				fd;
	int				tab;
	int				move;
	int				padding;
	char			*line;
	t_rtnode		*curr;
}					t_sda_env;

int					check_line(t_rtnode *node, char *s);

#endif
