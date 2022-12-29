/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/12/29 15:06:53 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	char	*s;
	char	*str_len;
	void	*mlx;
	void	*mlx_window;

	s = "hello world!\n";
	write(1, s, ft_strlen(s));
	str_len = ft_itoa(ft_strlen(s));
	write(1, str_len, ft_strlen(str_len));

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 640, 640, "my first window!");
	mlx_loop(mlx);
	
	return (0);
}
