/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:06:50 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/10 14:01:37 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_image
{
	void	*img_p;
	char	*pixel_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_grid
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
}	t_grid;

// note: img is not a pointer!
typedef struct s_mlx_data
{
	int		width;
	int		heigth;
	void	*mlx_p;
	void	*win_p;
	t_image	img;
	t_grid	grid;
}	t_mlx_data;

t_mlx_data	define_mlx_window(void);
t_grid		define_grid(int re_min, int re_max, int im_min, int im_max);
t_image		define_img(void *mlx_p, int height, int width);
void		add_pixel(t_image *img, int x, int y, int color);
void		calc_mandelbrot(t_mlx_data *mlx);
void		clear_image(t_mlx_data *mlx);

#endif
