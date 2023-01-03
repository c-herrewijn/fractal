/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 17:34:54 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 19:57:57 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	define_window(t_window *window)
{
	window->width = 640;
	window->heigth = 640;
}

void	define_grid(t_grid *grid)
{
	grid->im_min = -2;
	grid->im_max = 2;
	grid->re_min = -2;
	grid->re_max = 2;
}

void	add_pixel(t_image *img, int x, int y, int color)
{
	char	*pix;

	pix = img->pixel_data + y * img->size_line + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pix = color;
}
