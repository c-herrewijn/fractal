/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/10 14:12:20 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53) // Esc
	{
		mlx_destroy_image(mlx->mlx_p, mlx->img.img_p);
		mlx_destroy_window(mlx->mlx_p, mlx->win_p);
		exit(0);
	}
	if (keycode == 6) // z
	{
		clear_image(mlx);
		calc_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
	}
	return (1);
}

int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data = define_mlx_window();
	mlx_data.grid = define_grid(-2, 2, -2, 2);
	mlx_key_hook(mlx_data.win_p, key_event_handler, &mlx_data);
	mlx_loop(mlx_data.mlx_p);
}
