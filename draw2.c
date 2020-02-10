/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/09 03:52:29 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float			mod(float i)
{
	return ((i < 0) ? -i : i);
}

float			ft_max_float(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void			isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void			ft_zoom(t_point *p, t_fdf *data)
{
	p->x *= data->sp + data->zoom;
	p->y *= data->sp + data->zoom;
	p->x1 *= data->sp + data->zoom;
	p->y1 *= data->sp + data->zoom;
}

void			ft_shift(t_point *p, t_fdf *data)
{
	p->x += data->shift_x + data->marge_x;
	p->y += data->shift_y + data->marge_y;
	p->x1 += data->shift_x + data->marge_x;
	p->y1 += data->shift_y + data->marge_y;
}
