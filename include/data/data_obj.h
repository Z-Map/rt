/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarreel <lcarreel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:47:19 by lcarreel          #+#    #+#             */
/*   Updated: 2017/03/19 14:26:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_OBJ_H
# define DATA_OBJ_H

# include "mathex/vector.h"
# include "rt_prototype.h"

typedef struct			s_obj_parser
{
	t_blst				*v_blst;
	t_blst				*vn_blst;
	t_blst				*uv_blst;
	t_blst				*fv_blst;
	t_blst				*fuv_blst;
	t_blst				*fvn_blst;
}						t_objpars;

struct					s_obj
{
	t_objpars			*parser;
	t_v3f				*vertices;
	size_t				v_len;
	t_v3f				*normales;
	size_t				vn_len;
	t_v2f				*uv;
	size_t				uv_len;
	t_v3ui				*f_vertices;
	size_t				fv_len;
	t_v3ui				*f_uv;
	size_t				fuv_len;
	t_v3ui				*f_normales;
	size_t				fvn_len;
};

#endif
