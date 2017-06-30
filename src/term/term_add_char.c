/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_add_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:56:34 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:57:07 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_term.h"

static void	term_add_char_basic(t_term *term, char c)
{
	term->input[term->cursor] = c;
}

static void	term_add_char_spe_case(t_term *term, char c)
{
	int		cursor_end;

	cursor_end = term->size_use;
	while (cursor_end > term->cursor)
	{
		term->input[cursor_end] = term->input[cursor_end - 1];
		cursor_end--;
	}
	term->input[cursor_end] = c;
}

int			term_add_char(t_term *term, char c)
{
	if (term->cursor - 1 >= term->size_max || term->size_use >= term->size_max)
		return (1);
	if (term->cursor == term->size_use)
		term_add_char_basic(term, c);
	else
		term_add_char_spe_case(term, c);
	term->cursor += 1;
	term->size_use += 1;
	return (0);
}
