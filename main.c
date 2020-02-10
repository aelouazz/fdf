/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <aelouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/10 21:21:00 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		liberate_memory(t_fdf *data)
{
	if (data->z_matrix && *data->z_matrix)
	{
		free(*data->z_matrix);
		*data->z_matrix = NULL;
	}
	ft_bzero(data, sizeof(t_fdf));
	free(data);
	return (1);
}

void	fill_data(t_fdf *data)
{
	data->sp = 8;
	data->iso = 0;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 3;
	data->marge_x = (2000 - (data->width * (data->zoom + data->sp))) / 2;
	data->marge_y = (1300 - (data->height * (data->zoom + data->sp))) / 2;
	data->altt = 1;
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		if (ft_check(argv[1]) == -1)
			return (0);
		data = (t_fdf*)malloc(sizeof(t_fdf));
		ft_bzero(data, sizeof(t_fdf));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 1300, "fdf_1337");
		fill_data(data);
		draw(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_putendl("Usage : ./fdf <filename>");
	return (0);
}
