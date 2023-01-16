/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:18:33 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/16 14:21:14 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// i = -1 means the point never gets out (so inside the fractal body)
static int	color_selector(int i)
{
	int	modulo_nr;

	modulo_nr = i % 7;
	if (i == -1)
		return (0x00000000);
	else
		return (0x00880000 + (modulo_nr * 0x00112222));
}

static int	mandelbrot_test(const double re, const double im, int depth)
{
	int		i;
	double	z_re;
	double	z_im;
	double	re_tmp;
	double	im_tmp;

	z_re = re;
	z_im = im;
	i = 0;
	while (i < depth)
	{
		if ((z_re * z_re) + (z_im * z_im) >= 4)
			return (i);
		re_tmp = (z_re * z_re) - (z_im * z_im) + re;
		im_tmp = 2 * (z_re * z_im) + im;
		z_re = re_tmp;
		z_im = im_tmp;
		i++;
	}
	return (-1);
}

void	calc_mandelbrot(t_mlx_data *mlx)
{
	t_image		img;
	double		cplx_re;
	int			x;
	double		cplx_im;
	int			y;

	img = mlx->img;
	x = 0;
	clear_image(mlx);
	while (x < mlx->width)
	{
		cplx_re = mlx->grid.re_min
			+ ((double)x / mlx->width) * (mlx->grid.re_max - mlx->grid.re_min);
		y = 0;
		while (y < mlx->heigth)
		{
			cplx_im = mlx->grid.im_min + ((double)y / mlx->heigth)
				* (mlx->grid.im_max - mlx->grid.im_min);
			add_pixel(&img, x, y,
				color_selector(mandelbrot_test(cplx_re, cplx_im, 100)));
			y++;
		}
		x++;
	}
}
