/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/16 20:49:26 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	static char type = 'm';

	printf("keycode: %d\n", keycode);
	if (keycode == 53) // Esc
	{
		mlx_destroy_image(mlx->mlx_p, mlx->img.img_p);
		mlx_destroy_window(mlx->mlx_p, mlx->win_p);
		exit(0);
	}
	if (keycode == 8) // c
	{
		clear_image(mlx);
		set_default_grid(mlx);
		return (1);
	}
	if (keycode == 2) // d
		set_default_grid(mlx);
	if (keycode == 6) // z
		zoom_grid(mlx, 'i');
	if (keycode == 7) // x
		zoom_grid(mlx, 'o');
	if (keycode == 123) // left
		move_grid(mlx, 'l');
	if (keycode == 124) // right
		move_grid(mlx, 'r');
	if (keycode == 125) // up
		move_grid(mlx, 'u');
	if (keycode == 126) // down
		move_grid(mlx, 'd');

	// todo: don't calc fractal with other keys!!
	if (keycode == 5) // g
		type = 'g';
	if (keycode == 46) // m
		type = 'm';

	if (type == 'g')
		calc_mandelbrot(mlx, col_grad);
	if (type == 'm')
		calc_mandelbrot(mlx, col_mod);
	
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
	return (1);
}

int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data = define_mlx_window();
	set_default_grid(&mlx_data);
	mlx_key_hook(mlx_data.win_p, key_event_handler, &mlx_data);
	mlx_loop(mlx_data.mlx_p);
}
