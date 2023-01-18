/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:28:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/17 16:44:34 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_grid(t_mlx_data *mlx, char direction)
{
	long double	step_re;
	long double	step_im;

	step_re = (mlx->grid.re_max - mlx->grid.re_min);
	step_im = (mlx->grid.im_max - mlx->grid.im_min);
	if (direction == 'i')
	{
		mlx->grid.re_min += step_re / 10.0;
		mlx->grid.re_max -= step_re / 10.0;
		mlx->grid.im_min += step_im / 10.0;
		mlx->grid.im_max -= step_im / 10.0;
	}
	if (direction == 'o')
	{
		mlx->grid.re_min -= (step_re / 8.0);
		mlx->grid.re_max += (step_re / 8.0);
		mlx->grid.im_min -= (step_im / 8.0);
		mlx->grid.im_max += (step_im / 8.0);
	}
}

void	move_grid(t_mlx_data *mlx, char direction)
{
	long double	step_re;
	long double	step_im;

	step_re = (mlx->grid.re_max - mlx->grid.re_min) * 0.1;
	step_im = (mlx->grid.im_max - mlx->grid.im_min) * 0.1;
	if (direction == 'r')
	{
		mlx->grid.re_min += step_re;
		mlx->grid.re_max += step_re;
	}
	if (direction == 'l')
	{
		mlx->grid.re_min -= step_re;
		mlx->grid.re_max -= step_re;
	}
	if (direction == 'u')
	{
		mlx->grid.im_min += step_im;
		mlx->grid.im_max += step_im;
	}
	if (direction == 'd')
	{
		mlx->grid.im_min -= step_im;
		mlx->grid.im_max -= step_im;
	}
}

void	set_default_grid(t_mlx_data *mlx)
{
	mlx->grid = define_grid(-2, 2, -2, 2);
}

// debug!
void	print_grid(t_mlx_data *mlx)
{
	printf("re_min %Lf\n re_max %Lf\n im_min %Lf\n im_max %Lf\n\n",
		mlx->grid.re_min,
		mlx->grid.re_max,
		mlx->grid.im_min,
		mlx->grid.im_max);
}
