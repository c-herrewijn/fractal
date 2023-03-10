/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:23:41 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 14:30:48 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	j_test(t_cplx z, t_cplx c, int depth)
{
	int			i;
	long double	re_tmp;

	i = 0;
	while (i < depth)
	{
		if ((z.re * z.re) + (z.im * z.im) >= 4)
			return (i);
		re_tmp = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = 2 * (z.re * z.im) + c.im;
		z.re = re_tmp;
		i++;
	}
	return (-1);
}

void	calc_julia(t_mlx_data *mlx, int (*f_color)(int), t_cplx c)
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
			add_pixel(&img, x, y, f_color(j_test(z, c, 128)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
}

// assumes the input string is already validated!
t_cplx	create_julia_cplx(char *str_re, char *str_im)
{
	t_cplx	cplx;

	cplx.re = ft_atof_ld(str_re);
	cplx.im = ft_atof_ld(str_im);
	return (cplx);
}
