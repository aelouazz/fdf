/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/09 06:26:29 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_space(char *argv, char *line)
{
	int		fd;
	int		sum;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	if (get_next_line(fd, &line) == -1)
		return (0);
	sum = ft_count_words_sep(line, ' ');
	while (get_next_line(fd, &line) > 0)
		if (sum != ft_count_words_sep(line, ' '))
			return (-1);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int			ft_check_num(char *argv, char *line)
{
	int		fd;
	int		i;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == ',')
				i += 9;
			if ((ft_isdigit(line[i]) == 0) && line[i] != ' ' &&
				line[i] != '\t' && line[i] != '-')
				return (-1);
			i++;
		}
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int			ft_check_open(char *argv)
{
	int		fd;
	int		ret;
	char	line[10];

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	if ((ret = read(fd, line, 10)) <= 0)
		return (-1);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int			ft_check(char *argv)
{
	char	*line;

	line = "\0";
	if (ft_check_open(argv) == -1)
	{
		ft_putendl("Usage : check open");
		return (-1);
	}
	if (ft_check_num(argv, line) == -1)
	{
		ft_putendl("Usage : check num");
		return (-1);
	}
	if (ft_check_space(argv, line) == -1)
	{
		ft_putendl("Usage : check space");
		return (-1);
	}
	return (0);
}
