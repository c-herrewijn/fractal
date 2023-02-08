/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:14:51 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 10:00:49 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_p, mlx->img.img_p);
	mlx_destroy_window(mlx->mlx_p, mlx->win_p);
	exit(0);
}

int	mouse_event_handler(int button, int x, int y, t_mlx_data *mlx)
{
	if ((button == 4) || (button == 5))
	{
		if (button == 4)
			pos_zoom_grid(mlx, x, y, 'i');
		if (button == 5)
			pos_zoom_grid(mlx, x, y, 'o');
		calc_fractal(mlx);
	}
	return (1);
}

/*
/ Keycodes:
/  53 = Esc
/   6 = z
/   7 = x
/ 123 = left
/ 124 = right
/ 125 = down
/ 126 = up
*/
int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	if ((keycode == 53) || (keycode == 6) || (keycode == 7)
		|| ((keycode >= 123) && (keycode <= 126)))
	{		
		if (keycode == 53)
			close_window(mlx);
		if (keycode == 6)
			zoom_grid(mlx, 'i');
		if (keycode == 7)
			zoom_grid(mlx, 'o');
		if (keycode == 123)
			move_grid(mlx, 'l');
		if (keycode == 124)
			move_grid(mlx, 'r');
		if (keycode == 125)
			move_grid(mlx, 'd');
		if (keycode == 126)
			move_grid(mlx, 'u');
		calc_fractal(mlx);
	}
	return (1);
}
