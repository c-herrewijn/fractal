/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/27 22:37:04 by cherrewi      ########   odam.nl         */
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
	if (button == 4)
		pos_zoom_grid(mlx, x, y, 'i');
	if (button == 5)
		pos_zoom_grid(mlx, x, y, 'o');
	calc_mandelbrot(mlx, col_mod);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
	return (1);
}

int	key_event_handler(int keycode, t_mlx_data *mlx)
{
	static char	type = 'm';
	t_cplx		julia_test; // DEBUG!!

	// testing!
	julia_test.re = -1.5;
	julia_test.im = 0.0;

	printf("keycode: %d\n", keycode);
	if (keycode == 53) // Esc
		close_window(mlx);
	if (keycode == 8) // c
	{
		clear_image(mlx);
		set_default_grid(mlx);
		return (1);
	}
	if (keycode == 2) // d
		set_default_grid(mlx);
	if (keycode == 6) // z
		zoom_grid(mlx, 'i');
	if (keycode == 7) // x
		zoom_grid(mlx, 'o');
	if (keycode == 123) // left
		move_grid(mlx, 'l');
	if (keycode == 124) // right
		move_grid(mlx, 'r');
	if (keycode == 126) // up
		move_grid(mlx, 'u');
	if (keycode == 125) // down
		move_grid(mlx, 'd');
	
	if (keycode == 38) // j
	{
		calc_julia(mlx, col_mod, julia_test);
		mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
		return (1);
	}

	// todo: don't calc fractal with other keys!!
	if (keycode == 5) // g
		type = 'g';
	if (keycode == 46) // m
		type = 'm';

	if (type == 'g')
		calc_mandelbrot(mlx, col_grad);
	if (type == 'm')
		calc_mandelbrot(mlx, col_mod);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
	return (1);
}

int	input_valid(int argc, char**argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11))
		return (0);
	if (argc == 3)
		return (0);
	if (argc == 4 && !(ft_strncmp(argv[1], "Julia", 6) == 0
			&& is_valid_julia_coord(argv[2])
			&& is_valid_julia_coord(argv[3])))
		return (0);
	if (argc > 4)
		return (0);
	return (1);
}

void	print_manual(void)
{
	char	*err_message;

	err_message = ""
		"usage : ./fractol [fractal name] [real coord] [imaginary coord]\n"
		"fractal options:\n"
		"  Mandelbrot\n"
		"  Julia \n"
		"Note: input coordinates are only required for the Julia fractal and "
		"should each be in range [-2, 2]\n"
		"examples:\n"
		"  ./fractol Julia -1.5 0.0\n"
		"  ./fractol Mandelbrot\n";
	write(1, err_message, ft_strlen(err_message));
}

int	main(int argc, char *argv[])
{
	t_mlx_data	mlx_data;

	if (!input_valid(argc, argv))
	{
		print_manual();
	}
	else
	{
		mlx_data = define_mlx_window();
		set_default_grid(&mlx_data);
		mlx_hook(mlx_data.win_p, 17, 0, close_window, &mlx_data);
		mlx_mouse_hook (mlx_data.win_p, mouse_event_handler, &mlx_data);
		mlx_key_hook(mlx_data.win_p, key_event_handler, &mlx_data);
		mlx_loop(mlx_data.mlx_p);
	}		
	return (0);
}
