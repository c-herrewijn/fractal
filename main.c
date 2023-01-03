/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 19:16:55 by cherrewi      ########   odam.nl         */
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
	double		cplx_re;
	int			x;
	double		cplx_im;
	int			y;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 640, 640, "Fract-ol");
	img.img_ptr = mlx_new_image(mlx, 640, 640);
	img.pixel_data = mlx_get_data_addr(
			img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	grid.im_min = -2;
	grid.im_max = 2;
	grid.re_min = -2;
	grid.re_max = 2;
	window.width = 640;
	window.heigth = 640;

	x = 0;
	while (x < window.width)
	{
		cplx_re = -2 + ((double)x / 640) * (2 - -2);
		y = 0;
		while (y < window.heigth)
		{
			cplx_im = -2 + ((double)y / 640) * (2 - -2);
			if (mandelbrot_test(cplx_re, cplx_im, 1000))
			{
				add_pixel(&img, x, y, 0x00FF0000);
			}
			y++;
		}
		x++;
	}

	// put image to screen
	mlx_put_image_to_window(mlx, mlx_window, img.img_ptr, 0, 0);

	// img = mlx_new_image(mlx, 640, 640);
	mlx_loop(mlx);
	return (0);
}
