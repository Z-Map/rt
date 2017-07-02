/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sda.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 00:55:38 by lcarreel          #+#    #+#             */
/*   Updated: 2017/07/03 00:55:48 by lcarreel         ###   ########.fr       */
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

#endif
