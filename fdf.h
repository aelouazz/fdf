/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:06:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/09 07:25:37 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define R 15
# define P 35
# define D 2
# define I 34
# define U 32
# define ESC 53
# define MORE 69
# define LESS 78
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define MOD(a) ((a < 0) ? -a : a)

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			sp;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			marge_x;
	int			marge_y;
	int			iso;
	int			altt;
	int			error;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct	s_point
{
	float		x;
	float		y;
	float		x1;
	float		y1;
}				t_point;

void			fill_data(t_fdf *data);
float			ft_max_float(float a, float b);
void			isometric(float *x, float *y, int z);
void			ft_zoom(t_point *p, t_fdf *data);
void			ft_shift(t_point *p, t_fdf *data);
int				ft_check(char *argv);
int				liberate_memory(t_fdf *data);
void			draw(t_fdf *data);
void			read_file(char *file_name, t_fdf *data);
void			bresenham(t_point p, t_fdf *data);
float			mod(float i);
int				deal_key(int keycode, t_fdf *data);

#endif
