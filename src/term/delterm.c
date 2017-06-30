/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:56:16 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 19:56:18 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_term.h"
#include <stdlib.h>

void	delterm(t_term *term)
{
	if (term && (term->input))
		free(term->input);
	if (term)
		free(term);
}
