/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_del_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:57:12 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:57:42 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_term.h"
#include <stdio.h>

static void	term_del_char_basic(t_term *term)
{
	term->cursor -= 1;
	term->size_use -= 1;
	term->input[term->size_use] = 0;
}

static void	term_del_char_spe_case(t_term *term)
{
	int		cursor;

	if ((cursor = term->cursor - 1) < 0)
		return ;
	while (cursor < term->size_max)
	{
		term->input[cursor] = term->input[cursor + 1];
		cursor++;
	}
	term->input[cursor] = 0;
	term->cursor -= 1;
	term->size_use -= 1;
}

int			term_del_char(t_term *term)
{
	if (!term || !(term->input) || term->cursor <= 0)
		return (0);
	printf("%d | %d\n", term->cursor, term->size_use);
	if (term->cursor == term->size_use)
		term_del_char_basic(term);
	else
		term_del_char_spe_case(term);
	return (1);
}
