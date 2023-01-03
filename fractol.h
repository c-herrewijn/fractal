/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:06:50 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 20:04:52 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
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

void	define_grid(t_grid *grid);
void	define_window(t_window *window);
void	add_pixel(t_image *img, int x, int y, int color);
void	calc_mandelbrot(t_window window, t_grid grid, t_image *img);

#endif
