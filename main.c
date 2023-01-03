/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 15:29:06 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_image	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 640, 640, "Fract-ol");
	img.img_ptr = mlx_new_image(mlx, 640, 640);
	img.pixel_data = mlx_get_data_addr(
			img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	// tests
	printf("test 0.2: %d\n", mandelbrot_test(0.2, 0.0, 100));
	printf("test 0.3: %d\n", mandelbrot_test(0.3, 0.0, 100));

	// put pixel to image
	add_pixel(&img, 100, 100, 0x00FF0000);

	// put image to screen
	mlx_put_image_to_window(mlx, mlx_window, img.img_ptr, 0, 0);

	// img = mlx_new_image(mlx, 640, 640);
	mlx_loop(mlx);

	return (0);
}
