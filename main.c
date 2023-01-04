/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/04 17:04:16 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event_handler(int keycode, t_mlx *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->window);
	}
	return (1);
}

int	main(void)
{
	t_window	window;	
	t_grid		grid;
	t_mlx		mlx;
	t_image		img;
	int			keydown_event;
	int			key_mask;

	keydown_event = 2;
	key_mask = 1L << 0;
	window = define_window(640, 640);
	grid = define_grid(-2, 2, -2, 2);
	mlx = define_mlx(window);
	img = define_img(mlx, window);
	calc_mandelbrot(window, grid, &img);
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.img_ptr, 0, 0);
	mlx_hook(mlx.window, keydown_event, key_mask, key_event_handler, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
