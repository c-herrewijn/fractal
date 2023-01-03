/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:18:33 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 15:21:10 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_test(const double re, const double im, int depth)
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
