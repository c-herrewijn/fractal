/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:28:08 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/10 14:56:41 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_grid(t_mlx_data *mlx, double factor)
{
	mlx->grid = define_grid(
			mlx->grid.re_min * factor,
			mlx->grid.re_max * factor,
			mlx->grid.im_min * factor,
			mlx->grid.im_max * factor);
}

void	set_default_grid(t_mlx_data *mlx)
{
	mlx->grid = define_grid(-2, 2, -2, 2);
}
