/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:07:24 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/01/19 11:03:45 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
