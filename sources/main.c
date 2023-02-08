/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 09:51:57 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		"  ./fractol Julia -1.5 0.2\n"
		"  ./fractol Mandelbrot\n";
	write(1, err_message, ft_strlen(err_message));
}

int	main(int argc, char *argv[])
{
	t_mlx_data	mlx_data;

	if (!input_valid(argc, argv))
		print_manual();
	else
	{
		if (argc == 2)
		{
			mlx_data = define_mlx_window(1);
			calc_fractal(&mlx_data);
		}
		else
		{
			mlx_data = define_mlx_window(2);
			mlx_data.julia_coord = create_julia_cplx(argv[2], argv[3]);
			calc_fractal(&mlx_data);
		}
		mlx_hook(mlx_data.win_p, 17, 0, close_window, &mlx_data);
		mlx_mouse_hook (mlx_data.win_p, mouse_event_handler, &mlx_data);
		mlx_key_hook(mlx_data.win_p, key_event_handler, &mlx_data);
		mlx_loop(mlx_data.mlx_p);
	}		
	return (0);
}
