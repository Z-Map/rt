/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:19:26 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/12 14:48:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_CORE_H
# define RT_DATA_CORE_H

# include "rt_prototype.h"

struct				s_rt_gui
{
	mglwin			*win;
	mglwin			**wins;
	mglimg			*layer;
};

struct				s_rt_root
{
	unsigned long	flags;
	unsigned long	state;
	char			*scene;
	t_rtgui			gui;
};

#endif
