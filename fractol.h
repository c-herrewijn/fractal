/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:06:50 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/06 17:25:42 by cherrewi      ########   odam.nl         */
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
	void	*img_ptr;
	char	*pixel_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	t_image	img;
}	t_mlx;

typedef struct s_grid
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
}	t_grid;

typedef struct s_window
{
	int	width;
	int	heigth;
}	t_window;

t_window	define_window(int width, int height);
t_grid		define_grid(int re_min, int re_max, int im_min, int im_max);
t_mlx		define_mlx(t_window win);
t_image		define_img(void *mlx_ptr, t_window window);

void		add_pixel(t_image *img, int x, int y, int color);
void		calc_mandelbrot(t_window window, t_grid grid, t_image *img);

#endif
