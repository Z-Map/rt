/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkterm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:56:21 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:56:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "rt_term.h"
#include <stdio.h>

t_term		*mkterm(int size_max)
{
	t_term	*term;

	if (size_max < 1 || !(term = malloc(sizeof(t_term))))
		return (0);
	if (!(term->input = malloc(sizeof(char) * (size_max + 1))))
		return (0);
	memset(term->input, 0, size_max + 1);
	term->size_use = 0;
	term->size_max = size_max;
	term->cursor = 0;
	return (term);
}
