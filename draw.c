/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/09 03:52:31 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_it(t_point p, float x_step, float y_step, t_fdf *data)
{
	while ((int)(p.x - p.x1) || (int)(p.y - p.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p.x, p.y, data->color);
		p.x += x_step;
		p.y += y_step;
	}
}

void			bresenham(t_point p, t_fdf *data)
{
	float		x_step;
	float		y_step;
	int			max;
	int			z;
	int			z1;

	z = data->z_matrix[(int)p.y][(int)p.x] * data->altt;
	z1 = data->z_matrix[(int)p.y1][(int)p.x1] * data->altt;
	if (data->iso)
	{
		isometric(&p.x, &p.y, z);
		isometric(&p.x1, &p.y1, z1);
	}
	data->color = (z || z1) ? 0xe80c0c : 0xffffcc;
	ft_zoom(&p, data);
	ft_shift(&p, data);
	x_step = p.x1 - p.x;
	y_step = p.y1 - p.y;
	max = ft_max_float(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	put_it(p, x_step, y_step, data);
}

void			draw(t_fdf *data)
{
	t_point		p;

	p.y = 0;
	while ((int)p.y < data->height)
	{
		p.x = 0;
		while ((int)p.x < data->width)
		{
			if ((int)(p.x) < data->width - 1)
			{
				(p.y1 = (int)p.y);
				p.x1 = (int)p.x + 1;
				bresenham(p, data);
			}
			if ((int)(p.y) < data->height - 1)
			{
				(p.x1 = (int)p.x);
				p.y1 = (int)p.y + 1;
				bresenham(p, data);
			}
			p.x += 1;
		}
		p.y += 1;
	}
}
