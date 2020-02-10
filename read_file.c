/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/09 04:04:13 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_height(char *file_name)
{
	int			fd;
	int			height;
	char		*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int				get_width(char *file_name)
{
	int			fd;
	int			width;
	char		*line;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_count_words_sep(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void			fill_matrix(int *z_line, char *line)
{
	int			i;
	char		**nums;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		if (nums[i] == NULL)
			break ;
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void			read_file(char *file_name, t_fdf *data)
{
	int			i;
	int			fd;
	char		*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
