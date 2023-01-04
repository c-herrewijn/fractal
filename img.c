/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 17:34:54 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/04 17:00:09 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	define_window(int width, int height)
{
	t_window	window;

	window.width = width;
	window.heigth = height;
	return (window);
}

t_grid	define_grid(int re_min, int re_max, int im_min, int im_max)
{
	t_grid	grid;

	grid.im_min = im_min;
	grid.im_max = im_max;
	grid.re_min = re_min;
	grid.re_max = re_max;
	return (grid);
}

t_mlx	define_mlx(t_window win)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, win.width, win.heigth, "Fract-ol");
	return (mlx);
}

t_image	define_img(t_mlx mlx, t_window window)
{
	t_image	img;

	img.img_ptr = mlx_new_image(mlx.ptr, window.width, window.heigth);
	img.pixel_data = mlx_get_data_addr(
			img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

void	add_pixel(t_image *img, int x, int y, int color)
{
	char	*pix;

	pix = img->pixel_data + y * img->size_line + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pix = color;
}
