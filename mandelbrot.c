/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:18:33 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 20:03:50 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		if (pow(z_re, 2) + pow(z_im, 2) >= 4)
			return (0);
		re_tmp = pow(z_re, 2) - pow(z_im, 2) + re;
		im_tmp = 2 * (z_re * z_im) + im;
		z_re = re_tmp;
		z_im = im_tmp;
		i++;
	}
	return (1);
}

void	calc_mandelbrot(t_window window, t_grid grid, t_image *img)
{
	double		cplx_re;
	int			x;
	double		cplx_im;
	int			y;

	x = 0;
	while (x < window.width)
	{
		cplx_re = grid.re_min
			+ ((double)x / window.width) * (grid.re_max - grid.re_min);
		y = 0;
		while (y < window.heigth)
		{
			cplx_im = grid.im_min
				+ ((double)y / window.heigth) * (grid.im_max - grid.im_min);
			if (mandelbrot_test(cplx_re, cplx_im, 100))
				add_pixel(img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
