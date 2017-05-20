/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_matrix_parse.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:36:23 by lcarreel          #+#    #+#             */
/*   Updated: 2017/05/20 18:51:19 by lcarreel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_MATRIX_PARSE_H
# define DATA_MATRIX_PARSE_H

# include "rt_prototype.h"

int				vparse_rot(t_val *val, void *mem, t_gparse parser);
int				vparse_scale(t_val *val, void *mem, t_gparse parser);
int				vparse_trans(t_val *val, void *mem, t_gparse parser);

static const t_elm		g_el_mattfrot = {"rot", sizeof(t_mattf), 0, 0,
	NULL, NULL, NULL, vparse_rot, NULL};

static const t_elm		g_el_mattfscale = {"scale", sizeof(t_mattf), 0, 0,
	NULL, NULL, NULL, vparse_scale, NULL};

static const t_elm		g_el_mattftrans = {"trans", sizeof(t_mattf), 0, 0,
	NULL, NULL, NULL, vparse_trans, NULL};

#endif
