/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:07:24 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/09 14:19:03 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// NOTE: number of color functions should be alligned with rotate_color() !
t_color_func	get_color_func(int i)
{
	t_color_func	color_functions[3];

	color_functions[0] = col_mod;
	color_functions[1] = col_grad;
	color_functions[2] = col_mod_grad;
	return (color_functions[i % 3]);
}

// NOTE: number of color functions should be alligned with get_color_func() !
void	rotate_color(t_mlx_data *mlx)
{
	mlx->color_func_nr = (mlx->color_func_nr + 1) % 3;
}

// modulo base coloring
// i = -1 means inside the fractal body (so black)
int	col_mod(int i)
{
	int	modulo_nr;

	modulo_nr = i % 7;
	if (i == -1)
		return (0x00000000);
	else
		return (0x00880000 + (modulo_nr * 0x00112222));
}

// gradient based coloring (assumes depth 128)
int	col_grad(int i)
{
	if (i == -1)
		return (0x00000000);
	else
		return (0x00800000 + (i * 0x00010202));
}

// gradient based coloring (assumes depth 128)
int	col_mod_grad(int i)
{
	int	r;
	int	g;
	int	b;
	int	total;

	if (i == -1)
		return (0x00000000);
	else
	{
		r = ((0x12 + 6 * i) % 256) * 256 * 256;
		g = ((0x25 + 8 * i) % 256) * 256;
		b = ((0x80 + 4 * i) % 256);
		total = r + g + b;
		return (total);
	}
}
