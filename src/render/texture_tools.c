float		scalar_prod(t_point u, t_point v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z)
}


t_point		vec_dir(t_point a, t_point b)
{
	t_point		vec_ab;
	double		norme;
		
	vec_ab = new_point(b.x - a.x, b.y - a.y, b.z - a.z);		
	norme = sqrt(pow(vec_ab.x, 2) + pow(vec_ab.y, 2) + pow(vec_ab.z, 2));
	vec_ab.x /= norme;
	vec_ab.y /= norme;
	vec_ab.z /= norme;
	return (vec_ab);
}

int			new_point(float x, float y, float z)
{
	t_point		pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

t_point			rot_point(t_point point, float *m16)
{
	t_point		new_point;
	float		*m4;

	m4 = (float *)malloc(sizeof(float) * 4);
	m4[0] = point.x;
	m4[1] = point.y;
	m4[2] = point.z;
	m4 = prod_mat(m4, m16);
	new_point.x = m4[0];
	new_point.y = m4[1];
	new_point.z = m4[2];
	if (m4)
		free(m4);
	return (new_point);
}


float	*get_rot_mat(float a, float b, float c)
{
	float		*tab;

	tab = (float *)malloc(sizeof(tab) * 16);
	if (!tab)
		return (NULL);
	tab[0] = cos(b) * cos(c);
	tab[1] = -cos(b) * sin(c);
	tab[2] = sin(b);
	tab[3] = 0;
	tab[4] = sin(a) * sin(b) * cos(c) + cos(a) * sin(c);
	tab[5] = -sin(a) * sin(b) * sin(c) + cos(a) * cos(c);
	tab[6] = -sin(a) * cos(b);
	tab[7] = 0;
	tab[8] = -cos(a) * sin(b) * cos(c) + sin(a) * sin(c);
	tab[9] = cos(a) * sin(b) * sin(c) + sin(a) * cos(c);
	tab[10] = cos(a) * cos(b);
	tab[11] = 0;
	tab[12] = 0;
	tab[13] = 0;
	tab[14] = 0;
	tab[15] = 1;
	return (tab);
}
