/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:04:06 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/31 06:29:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "render.h"
#include "shaders.h"

static unsigned int	get_background_color(t_render *r)
{
	t_texture		*tex;
	unsigned int	*pixels_texture;
	double			u;
	double			v;

	if (!r->rt->settings.skybox)
		return (r->rt->settings.bgcolor);
	tex = r->rt->settings.skybox;
	pixels_texture = tex->surface->pixels;
	u = 0.5 + (atan2(r->ray->dir.z, r->ray->dir.x) / (2.0 * M_PI));
	v = 0.5 - (asin(r->ray->dir.y) / M_PI);
	return (pixels_texture[tex->surface->w *
		(int)(v * tex->surface->h) + (int)(u * tex->surface->w)]);
}

static int			rt_render_csg(t_obj *obj, const t_render *r, t_intersect *v)
{
	const char		on = obj->flags & FLAG_CSG_NEGATIVE;
	const char		sn = r->ray->flags & FLAG_CSG_NEGATIVE;

	if ((!on) && (!sn))
		return (OK);
	if ((on) && (!sn))
	{
		r->ray->flags |= FLAG_CSG_NEGATIVE;
		if (v->flags & INTER_OUT)
			r->ray->lenght = geo_distv4(r->ray->start, v->out);
		else
			r->ray->lenght = (double)INFINITY;
		return (-1);
	}
	if ((on) && (sn))
	{
		r->ray->flags ^= FLAG_CSG_NEGATIVE;
		r->ray->lenght = geo_distv4(r->ray->start, v->in);
		return (OK);
	}
	return (-1);
}

int					rt_render_foreach(t_obj *obj, int mode, void *userdata)
{
	t_render		*r;
	t_intersect		impact;

	(void)mode;
	impact = (t_intersect){geo_dtov4d(0.0), geo_dtov4d(0.0), 0};
	r = userdata;
	if ((!(obj->type & NOCHECKBOX)) &&
		(!raybox_cube_check(r->ray, &obj->bounds)))
		return (STOP_NODE);
	if ((obj->type & NOCHECKBOX) || (raybox_cube_check(r->ray, &obj->hitbox)))
	{
		IFRET__(!(obj->type & VISIBLE), OK);
		if ((obj->inters) && (obj->inters(obj, r->ray, &impact) == 0))
			;
		else if (r->lowest_lenght < r->ray->lenght)
			;
		else if (rt_render_csg(obj, r, &impact) == OK)
		{
			r->obj_intersect = obj;
			r->intersection = impact.in;
			r->lowest_lenght = r->ray->lenght;
		}
	}
	return (OK);
}

unsigned int		rt_render_ray(t_rt *rt, t_ray *ray)
{
	t_render	r;

	r = (t_render){
		ray, rt, NULL, HUGE_VAL, 0.0,
		(t_v4d){0.0, 0.0, 0.0, 0.0},
		ray->dir
	};
	ray->flags = 0;
	ray->intersect.flags = 0;
	ray->color = 0xff000000;
	rt_node_foreach(rt->tree.bounded, INFIX, &rt_render_foreach, &r);
	rt_node_foreach(rt->tree.unbounded, INFIX, &rt_render_foreach, &r);
	if ((r.obj_intersect) && (r.obj_intersect->flags & FLAG_CSG_NEGATIVE))
		r.obj_intersect = NULL;
	if (r.obj_intersect)
	{
		r.normal = r.obj_intersect->normal(r.obj_intersect, &(r.intersection));
		rt_node_foreach(rt->tree.light, INFIX, &rt_render_light, &r);
		r.ray->color = shaders_compute_color(r.obj_intersect->shader,
			0xff000000);
	}
	ray->lenght = r.lowest_lenght;
	if (!r.obj_intersect)
		return (get_background_color(&r));
	return (rt_render_opacity(rt, ray, &r));
}

unsigned int		rt_render_bray(t_rt *rt, t_ray *ray)
{
	t_render	r;

	r = (t_render){
		ray, rt,
		NULL,
		HUGE_VAL,
		0.0,
		(t_v4d){0.0, 0.0, 0.0, 0.0},
		ray->dir
	};
	ray->color = 0xff000000;
	rt_node_foreach(rt->tree.bounded, INFIX, &rt_render_foreach, &r);
	rt_node_foreach(rt->tree.unbounded, INFIX, &rt_render_foreach, &r);
	if (r.obj_intersect)
		r.ray->color = ((t_cube *)r.obj_intersect->content)->color;
	else
		return (get_background_color(&r));
	ray->lenght = r.lowest_lenght;
	return (rt_render_opacity(rt, ray, &r));
}

void				rt_render(t_rt *rt)
{
	if ((rt->settings.mode & MODE) == ALTERNATIVEMODE)
		rt_init_alterate_rendermode(rt, &rt_rays);
	else
		rt_init_rt_rendermode(rt, &rt_rays);
}
