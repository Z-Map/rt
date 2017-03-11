/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:08:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/11 19:22:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CORE_H
# define RT_CORE_H

# include "rt_prototype.h"
# include "data/rt_data_core.h"

int			rt_main(t_rt *rt);

int			rt_init_scenerdr(t_rt *rt);
int			rt_init_mglw(t_rt *rt);
int			rt_run(t_rt *rt);

int			rt_error(t_rt *rt, int code, const char *msg);
int			rt_check_error(t_rt *rt);

int			rt_quit(t_rt *rt);

#endif
