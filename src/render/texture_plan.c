static float	nor_x(t_obj object, t_point inter)
{
	float	x;

	x = inter.x - object.offset_x - floor((inter.x - object.offset_x)
		/ object.text_x) * object.text_x;
	x = x / object.text_x * object.texture->width;
	return (x);
}

static float	nor_y(t_obj object, t_point inter)
{
	float	y;

	y = inter.z - object.offset_y - floor((inter.z - object.offset_y)
		/ object.text_y) * object.text_y;
	y = (object.text_y - y) / object.text_y * object.texture->height;
	return (y);
}

t_color			texture_plan(t_obj object, t_point inter)
{
	int		colo;
	t_point	rot;
	float	calc;
	t_plan	*tmp;

	tmp = ((t_plan *)object.obj);
	if (!object.texture)
		return (object.color);
	rot = vec_dir(new_point(0, 0, 0), new_point(tmp->a, tmp->b, tmp->c));
	calc = rot.x + rot.y + rot.z;
	inter = rot_point(new_point(inter.x - rot.x * (tmp->d /
		(tmp->a + tmp->b + tmp->c)),
		inter.y - rot.y * (tmp->d / (tmp->a + tmp->b + tmp->c)),
		inter.z - rot.z * (tmp->d / (tmp->a + tmp->b + tmp->c))),
		get_rot_mat(M_PI / 2 * rot.z / calc, 0, -M_PI / 2 * rot.x / calc));
	colo = 0;
	ft_memcpy(&colo, object.texture->data + ((int)nor_x(object, inter) *
		(object.texture->bpp / 8)) + ((int)nor_y(object, inter)
		* object.texture->sl), 3);
	return (color_int(colo));
}
