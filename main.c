/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:03:27 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/12/27 20:06:18 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	char	*s;
	char	*str_len;

	s = "hello world!\n";
	write(1, s, ft_strlen(s));
	str_len = ft_itoa(ft_strlen(s));
	write(1, str_len, ft_strlen(str_len));
	return (0);
}
