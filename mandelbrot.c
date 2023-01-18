/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:18:33 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/18 17:09:05 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// modulo base coloring
// i = -1 means inside the fractal body (so black)
int	col_mod(int i)
{
	int	modulo_nr;

	modulo_nr = i % 7;
	if (i == -1)
		return (0x00000000);
	else
		return (0x00880000 + (modulo_nr * 0x00112222));
}

// gradient based coloring (assumes depth 128)
int	col_grad(int i)
{
	if (i == -1)
		return (0x00000000);
	else
		return (0x00800000 + (i * 0x00010202));
}

// mandelbrot test
static int	m_test(const long double re, const long double im, int depth)
{
	int		i;
	long double	z_re;
	long double	z_im;
	long double	re_tmp;
	long double	im_tmp;

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

void	calc_mandelbrot(t_mlx_data *mlx, int (*f_color)(int))
{
	t_image			img;
	long double		cplx_re;
	int				x;
	long double		cplx_im;
	int				y;

	img = mlx->img;
	x = 0;
	clear_image(mlx);
	while (x < mlx->width)
	{
		cplx_re = mlx->grid.re_min
			+ ((long double)x / mlx->width) * (mlx->grid.re_max - mlx->grid.re_min);
		y = 0;
		while (y < mlx->heigth)
		{
			cplx_im = mlx->grid.im_max - ((long double)y / mlx->heigth)
				* (mlx->grid.im_max - mlx->grid.im_min);
			add_pixel(&img, x, y, f_color(m_test(cplx_re, cplx_im, 128)));
			y++;
		}
		x++;
	}
}
