/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:22:22 by aelouazz          #+#    #+#             */
/*   Updated: 2020/02/09 07:44:36 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key2(int keycode, t_fdf *data)
{
	if (keycode == I && data->iso == 0)
	{
		data->iso = 1;
		data->shift_x += data->width * data->sp * data->zoom / 13;
	}
	if (keycode == P && data->iso == 1)
	{
		data->iso = 0;
		data->shift_x -= data->width * data->sp * data->zoom / 13;
	}
	if (keycode == U)
		data->altt += 1;
	if (keycode == D)
		data->altt -= 1;
}

void	key1(int keycode, t_fdf *data)
{
	if (keycode == UP_ARROW)
		data->shift_y -= 20;
	if (keycode == DOWN_ARROW)
		data->shift_y += 20;
	if (keycode == LEFT_ARROW)
		data->shift_x -= 20;
	if (keycode == RIGHT_ARROW)
		data->shift_x += 20;
	if (keycode == MORE)
	{
		data->zoom += 2;
		data->shift_x -= data->width;
		data->shift_y -= data->width / 2;
	}
	if (keycode == ESC && liberate_memory(data))
		exit(0);
}

int		deal_key(int keycode, t_fdf *data)
{
	key1(keycode, data);
	key2(keycode, data);
	if (keycode == LESS)
	{
		data->zoom -= 2;
		data->shift_x += data->width;
		data->shift_y += data->width / 2;
		if (data->zoom < 0)
		{
			data->zoom += 2;
			data->shift_x -= data->width;
			data->shift_y -= data->width / 2;
		}
	}
	if (keycode == R)
		fill_data(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
