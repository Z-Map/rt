/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:53:42 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:54:11 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

#include "data/data_term.h"
#include "rt_prototype.h"

t_term		*mkterm(int size_max);
void		delterm(t_term *term);

int			term_add_char(t_term *term, char c);

int			term_del_char(t_term *term);

void		term_moove_right(t_term *term);

void		term_moove_left(t_term *term);

void		term_moove_top(t_term *term);

void		term_moove_bottom(t_term *term);

#endif
