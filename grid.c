/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:28:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/18 17:26:48 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pos_zoom_grid(t_mlx_data *mlx, int x, int y, char direction)
{
	long double	step_re;
	long double	step_im;
	long double	re_click;
	long double	im_click;

	step_re = (mlx->grid.re_max - mlx->grid.re_min);
	step_im = (mlx->grid.im_max - mlx->grid.im_min);
	re_click = mlx->grid.re_min + ((long double)x / mlx->width) * step_re;
	im_click = mlx->grid.im_min + (1 - (long double)y / mlx->heigth) * step_im;
	if (direction == 'i')
	{
		mlx->grid.re_min += (0.2 * (re_click - mlx->grid.re_min));
		mlx->grid.re_max -= (0.2 * (mlx->grid.re_max - re_click));
		mlx->grid.im_min += (0.2 * (im_click - mlx->grid.im_min));
		mlx->grid.im_max -= (0.2 * (mlx->grid.im_max - im_click));
	}
	if (direction == 'o')
	{
		// todo;
		puts("todo: mouse zoom out!");
	}

	// debug
	printf("re_click %LF\nim_click %LF\n", re_click, im_click);
	printf("step_re %LF\nstep_im %LF\n", step_re, step_im);
}

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
