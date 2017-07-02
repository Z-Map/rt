/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:53:45 by alhelson          #+#    #+#             */
/*   Updated: 2017/06/18 20:53:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_texture.h"

static int		g_hash[] =
{208, 34, 231, 213, 32, 248, 233, 56, 161, 78, 24,
	140, 71, 48, 140, 254, 245, 255, 247, 247, 40,
	185, 248, 251, 245, 28, 124, 204, 204, 76, 36,
	1, 107, 28, 234, 163, 202, 224, 245, 128, 167, 204,
	9, 92, 217, 54, 239, 174, 173, 102, 193, 189, 190,
	121, 100, 108, 167, 44, 43, 77, 180, 204, 8, 81,
	70, 223, 11, 38, 24, 254, 210, 210, 177, 32, 81, 195,
	243, 125, 8, 169, 112, 32, 97, 53, 195, 13,
	203, 9, 47, 104, 125, 117, 114, 124, 165, 203, 181,
	235, 193, 206, 70, 180, 174, 0, 167, 181, 41,
	164, 30, 116, 127, 198, 245, 146, 87, 224, 149,
	206, 57, 4, 192, 210, 65, 210, 129, 240, 178, 105,
	228, 108, 245, 148, 140, 40, 35, 195, 38, 58, 65,
	207, 215, 253, 65, 85, 208, 76, 62, 3, 237, 55, 89,
	232, 50, 217, 64, 244, 157, 199, 121, 252, 90, 17,
	212, 203, 149, 152, 140, 187, 234, 177, 73, 174,
	193, 100, 192, 143, 97, 53, 145, 135, 19, 103, 13, 90,
	135, 151, 199, 91, 239, 247, 33, 39, 145,
	101, 120, 99, 3, 186, 86, 99, 41, 237, 203, 111, 79, 220,
	135, 158, 42, 30, 154, 120, 67, 87, 167,
	135, 176, 183, 191, 253, 115, 184, 21, 233, 58, 129,
	233, 142, 39, 128, 211, 118, 137, 139, 255,
	114, 20, 218, 113, 154, 27, 127, 246, 250, 1, 8, 198,
	250, 209, 92, 222, 173, 21, 88, 102, 219};

static int		noise_3v(int x, int y, int z)
{
	int			v;

	v = g_hash[((int)(x)) % 256];
	v = g_hash[(((int)(y)) + v) % 256];
	v = g_hash[(((int)(z)) + v) % 256];
	return (v);
}

/*
** trilinear interpolation
*/

float			terp(t_v3i v3i, t_v3i v3i2, t_v3f fact)
{
	double		v[8];

	v[0] = (float)noise_3v(v3i.x, v3i.y, v3i.z);
	v[1] = (float)noise_3v(v3i2.x, v3i.y, v3i.z);
	v[2] = (float)noise_3v(v3i.x, v3i2.y, v3i.z);
	v[3] = (float)noise_3v(v3i2.x, v3i2.y, v3i.z);
	v[4] = (float)noise_3v(v3i.x, v3i.y, v3i2.z);
	v[5] = (float)noise_3v(v3i2.x, v3i.y, v3i2.z);
	v[6] = (float)noise_3v(v3i.x, v3i2.y, v3i2.z);
	v[7] = (float)noise_3v(v3i2.x, v3i2.y, v3i2.z);
	v[0] = lerp(fact.x, v[0], v[1]);
	v[1] = lerp(fact.x, v[4], v[5]);
	v[2] = lerp(fact.x, v[2], v[3]);
	v[3] = lerp(fact.x, v[6], v[7]);
	v[0] = lerp(fact.y, v[0], v[2]);
	v[1] = lerp(fact.y, v[1], v[3]);
	return (lerp(fact.z, v[0], v[1]));
}

float			noise_3d(t_v3f vec)
{
	t_v3f		factor;
	t_v3i		v3i;
	t_v3i		v3i2;

	v3i = (t_v3i){.x = (int)vec.x, .y = (int)vec.y, .z = (int)vec.z};
	v3i2 = (t_v3i){.x = v3i.x + 1, .y = v3i.y + 1, .z = v3i.z + 1};
	factor = (t_v3f){vec.x - ((float)(v3i.x)),
	vec.y - ((float)(v3i.y)), vec.z - ((float)(v3i.z))};
	return (terp(v3i, v3i2, factor));
}

float			turbulance(t_v3f vec, float freq, float depth)
{
	t_v3f		va;
	float		amp;
	float		fin;
	float		div;
	int			i;

	amp = 1.0;
	fin = 0.0;
	div = 0.0;
	va = (t_v3f){vec.x * freq, vec.y * freq, vec.z * freq};
	i = 0;
	while (i < depth)
	{
		div += 256 * amp;
		fin += noise_3d(va) * amp;
		amp /= 2;
		va.x *= 2;
		va.y *= 2;
		va.z *= 2;
		i++;
	}
	return (fin / div);
}

float			rtex_proc_perlin(t_v3f vec)
{
	return (turbulance(vec, 0.1, 4.0) * 255.0);
}
