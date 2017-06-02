t_color	texture_sphere(t_obj object, t_point normal, t_vector ray)
{
	float	phi;
	float	u;
	float	v;
	float	theta;
	int		colo;

	if ((colo = 0) || !object.texture)
		return (object.color);
	normal = normal_sphere(*(t_sphere *)(object.obj), normal, ray);
	phi = acos(-scalar_prod(new_point(0, -1, 0), normal));
	v = phi / M_PI;
	theta = acos(fmod(scalar_prod(normal, new_point(0, 0, -1)), 1) /
		sin(phi)) / (2 * M_PI);
	u = (scalar_prod(new_point(1, 0, 0), normal) > 0) ? theta : 1 - theta;
	if (scalar_prod(normal, new_point(0, 0, -1)) / sin(phi) < -1)
		u = 0.5;
	u = (int)ceil(u * object.texture->width * object.rep)
		% (int)object.texture->width;
	v = (int)ceil(v * object.texture->height * object.rep) %
		(int)object.texture->height;
	ft_memcpy(&colo, object.texture->data + ((int)u *
		(object.texture->bpp / 8)) + ((int)v * object.texture->sl), 3);
	return (color_int(colo));
}

t_point			normal_sphere(t_sphere sph, t_point inter)
{
	return (vec_dir(inter, sph.center));
}
