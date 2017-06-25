/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_moove_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:57:49 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:58:13 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_term.h"

void	term_moove_right(t_term *term)
{
	if (term->cursor <= term->size_use)
		term->cursor += 1;
}

void	term_moove_left(t_term *term)
{
	if (term->cursor > 0)
		term->cursor += 1;
}

void	term_moove_top(t_term *term)
{
	term->cursor = term->size_use;
}

void	term_moove_bottom(t_term *term)
{
	term->cursor = 0;
}
