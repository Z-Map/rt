/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:52:21 by fanno             #+#    #+#             */
/*   Updated: 2017/05/17 16:48:54 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		**node_prefix(t_rtnode *node)
{
	void		**tmp;
	
	tmp = &node;
	while (*tmp)
	{
		if (!node->child)
		{
			if (t_rtnode->t_rtobi->obj.type | SPHERE)
				tmp++ = calc_sphere;
			if (t_rtnode->t_rtobi->obj.type | CONE)
				tmp++ = calc_cone;
			if (t_rtnode->t_rtobi->obj.type | PLAN)
				tmp++ = calc_plan;
			if (t_rtnode->t_rtobi->obj.type | CYLINDER)
				tmp++ = calc_cylinder
		}
		if (!node->next)
			if (t_rtnode->t_rtobi->obj.type | SPHERE)
				tmp++ = calc_sphere;
			if (t_rtnode->t_rtobi->obj.type | CONE)
				tmp++ = calc_cone;
			if (t_rtnod0e->t_rtobi->obj.type | PLAN)
				tmp++ = calc_plan;
			if (t_rtnode->t_rtobi->obj.type | CYLINDER)
				tmp++ = calc_cylinder
		}
	}
}
// Pour le moment la fonction est en iteratif. Il faut je pense la passer en 
// recursive, cela s'adaptera mieux a la structure du nodetree.
// mon void** est un type par default, a creuser.

double		calc_delta(double a, double b, double c)
{
	double	t0;
	double	t1;
	double	t;

	if ((b * b) - (4 * a * c) < 0)
		return (0);
	t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	t = (t0 > 0 && (t0 < t1 || t1 <= 0)) ? t0 : t1;
	t = (t > 0) ? t : -8;
	return (t);
}

double		calc_plane()
{
}
double		calc_sphere()
{
}
double		calc_cone()
{
}
double		calc_cylinder()
{
}
