/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:18:33 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/09 13:32:09 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	m_test(t_cplx c, int depth)
{
	int			i;
	long double	z_re;
	long double	z_im;
	long double	re_tmp;

	z_re = c.re;
	z_im = c.im;
	i = 0;
	while (i < depth)
	{
		if ((z_re * z_re) + (z_im * z_im) >= 4)
			return (i);
		re_tmp = (z_re * z_re) - (z_im * z_im) + c.re;
		z_im = 2 * (z_re * z_im) + c.im;
		z_re = re_tmp;
		i++;
	}
	return (-1);
}

void	calc_mandelbrot(t_mlx_data *mlx, int (*f_color)(int))
{
	t_image			img;
	t_cplx			z;
	int				x;
	int				y;

	img = mlx->img;
	x = 0;
	clear_image(mlx);
	while (x < mlx->width)
	{
		z.re = mlx->grid.re_min + ((long double)x / mlx->width)
			* (mlx->grid.re_max - mlx->grid.re_min);
		y = 0;
		while (y < mlx->heigth)
		{
			z.im = mlx->grid.im_max - ((long double)y / mlx->heigth)
				* (mlx->grid.im_max - mlx->grid.im_min);
			add_pixel(&img, x, y, f_color(m_test(z, 128)));
			y++;
		}
		x++;
	}
}

void	calc_fractal(t_mlx_data *mlx)
{
	t_color_func	color_func;

	color_func = get_color_func(mlx->color_func_nr);
	if (mlx->fractal_nr == 0)
		calc_mandelbrot(mlx, color_func);
	if (mlx->fractal_nr == 1)
		calc_julia(mlx, color_func, mlx->julia_coord);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
}

void	rotate_fractal(t_mlx_data *mlx)
{
	int		fractal_nr;

	fractal_nr = (mlx->fractal_nr + 1) % 2;
	mlx->fractal_nr = fractal_nr;
	if (fractal_nr == 1)
	{
		mlx->julia_coord = get_center_coord(mlx);
	}
	mlx->grid = define_grid(-2, 2, -2, 2);
}
