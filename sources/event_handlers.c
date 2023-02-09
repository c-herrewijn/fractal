/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handlers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:14:51 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/09 12:49:46 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_key_options(void)
{
	char	*err_message;

	err_message = ""
		"Keyboard options:\n"
		"Esc     close window, end program\n"
		"z       zoom in\n"
		"x       zoom out\n"
		"c       change color function\n"
		"f       switch fractal\n"
		"          note: the center of the Mandelbrot fractal is used as input"
		" for the Julia fractal\n"
		"left    pan left\n"
		"right   pan right\n"
		"down    pan up\n"
		"up      pan down\n"
		"Mouse options:\n"
		"scroll up     zoom in\n"
		"scroll down   zoom out\n";
	write(1, err_message, ft_strlen(err_message));
}

static void	update_fractal(int keycode, t_mlx_data *mlx)
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
	if (keycode == 3)
		rotate_fractal(mlx);
	calc_fractal(mlx);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_p, mlx->img.img_p);
	mlx_destroy_window(mlx->mlx_p, mlx->win_p);
	exit(0);
}

/*
/ Keycodes:
/  53 = Esc     close window, end program
/   6 = z       zoom in
/   7 = x       zoom out
/	8 = c       change color function
/   3 = f       change fractal
/ 123 = left    pan left
/ 124 = right   pan right
/ 125 = down    pan up
/ 126 = up      pan down
*/
int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	if ((keycode == 53) || (keycode == 6) || (keycode == 7) || (keycode == 8)
		|| (keycode == 3) || ((keycode >= 123) && (keycode <= 126)))
	{		
		update_fractal(keycode, mlx);
	}
	else
		print_key_options();
	return (1);
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
