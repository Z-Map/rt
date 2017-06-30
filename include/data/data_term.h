/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_term.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:49:39 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/25 20:02:03 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TERM_H
# define DATA_TERM_H

struct			s_term
{
	int			size_use;
	int			size_max;
	int			cursor;
	int			padding;
	char		*input;
};

#endif
