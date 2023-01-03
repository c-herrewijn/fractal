/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/29 17:34:54 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/03 15:27:10 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_pixel(t_image *img, int x, int y, int color)
{
	char	*pix;

	pix = img->pixel_data + y * img->size_line + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pix = color;
}
