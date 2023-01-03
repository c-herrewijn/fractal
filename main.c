/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 19:58:17 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void		*mlx;
	void		*mlx_window;
	t_image		img;
	t_window	window;	
	t_grid		grid;

	define_window(&window);
	define_grid(&grid);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 640, 640, "Fract-ol");
	img.img_ptr = mlx_new_image(mlx, 640, 640);
	img.pixel_data = mlx_get_data_addr(
			img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	calc_mandelbrot(window, grid, &img);
	mlx_put_image_to_window(mlx, mlx_window, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}
