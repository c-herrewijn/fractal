/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 17:34:54 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 12:50:29 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx_data	define_mlx_window(int fract_nr)
{
	t_mlx_data	mlx_data;
	int			width;
	int			height;
	void		*mlx_p;

	width = 640;
	height = 640;
	mlx_p = mlx_init();
	mlx_data.mlx_p = mlx_p;
	mlx_data.win_p = mlx_new_window(mlx_p, width, height, "Fract-ol");
	mlx_data.img = define_img(mlx_p, width, height);
	mlx_data.grid = define_grid(-2, 2, -2, 2);
	mlx_data.width = width;
	mlx_data.heigth = height;
	mlx_data.fractal_nr = fract_nr;
	mlx_data.color_func_nr = 0;
	return (mlx_data);
}

t_grid	define_grid(long double re_min, long double re_max,
	long double im_min, long double im_max)
{
	t_grid	grid;

	grid.im_min = im_min;
	grid.im_max = im_max;
	grid.re_min = re_min;
	grid.re_max = re_max;
	return (grid);
}

t_image	define_img(void *mlx_p, int width, int height)
{
	t_image	img;

	img.img_p = mlx_new_image(mlx_p, width, height);
	img.pixel_data = mlx_get_data_addr(
			img.img_p, &img.bits_per_pixel, &img.size_line, &img.endian);
	return (img);
}

void	add_pixel(t_image *img, int x, int y, int color)
{
	char	*pix;

	pix = img->pixel_data + y * img->size_line + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pix = color;
}

void	clear_image(t_mlx_data *mlx)
{
	t_image		img;
	int			x;
	int			y;

	img = mlx->img;
	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->heigth)
		{
			add_pixel(&img, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
}
