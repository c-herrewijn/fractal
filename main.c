/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/09 15:36:23 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, t_mlx *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
		mlx_destroy_window(mlx->ptr, mlx->window);
		exit(0);
	}
	return (keycode);
}

int	main(void)
{
	t_window	window;	
	t_grid		grid;
	t_mlx		mlx;

	window = define_window(640, 640);
	grid = define_grid(-2, 2, -2, 2);
	mlx = define_mlx(window);
	calc_mandelbrot(window, grid, &mlx.img);

	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.window, key_event_handler, &mlx);
	mlx_loop(mlx.ptr);
}
