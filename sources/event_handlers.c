/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:14:51 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 12:55:57 by cherrewi      ########   odam.nl         */
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
/  53 = Esc		close window, end program
/   6 = z		zoom in
/   7 = x		zoom out
/	8 = c		change color function
/ 123 = left	pan left
/ 124 = right	pan right
/ 125 = down	pan up
/ 126 = up		pan down
*/
int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	if ((keycode == 53) || (keycode == 6) || (keycode == 7) || (keycode == 8)
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
		if (keycode == 8)
			rotate_color(mlx);
		calc_fractal(mlx);
	}
	return (1);
}
