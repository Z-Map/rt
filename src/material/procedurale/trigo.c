/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:47:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/06/11 22:33:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathex/vector.h"
#include "mathex/utils.h"
#include "rt_texture.h"

float		rtex_proc_trigo(t_v3f vec)
{
	float	a;

	a = len3f(*pfrac3f(&vec));
	return (mxmaxf(1.0f - a, 0.0f));
}

float		rtex_proc_bubble(t_v3f vec)
{
	float	a;

	a = len3f(*pfrac3f(&vec));
	if (a > 1.0f)
		a = 0.0f;
	return (a);
}


float		rtex_proc_circle(t_v3f vec)
{
	float	a;

	a = (fmodf(len3f(vec), 2.0f) - 1.5f) * 2.0f;
	return (1.0f - mxminf(mxabsf(a), 1.0f));
}
