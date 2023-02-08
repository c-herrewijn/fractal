/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:05:41 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 10:04:15 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
* converts a string to a long double
* assumes the input string is already validated!
*/
long double	ft_atof_ld(char *str)
{
	long double	ld_int_part;
	long double	ld_fract_part;
	int			i;

	ld_int_part = 0.0l;
	ld_fract_part = 0.0l;
	i = (str[0] == '-');
	while (str[i] != '\0'
		&& (ft_strchr(str, '.') == NULL || str + i < ft_strchr(str, '.')))
	{
		ld_int_part *= 10.0l;
		ld_int_part += ((long double)(str[i] - '0'));
		i++;
	}
	i = ft_strlen(str) - 1;
	while (ft_strchr(str, '.') != NULL
		&& i >= 0 && (str + i) > ft_strchr(str, '.'))
	{
		ld_fract_part += ((long double)(str[i] - '0'));
		ld_fract_part /= 10.0l;
		i--;
	}
	return (((long double)(1 - 2 * (str[0] == '-')))
		* (ld_int_part + ld_fract_part));
}

// assumes the input string is already validated!
t_cplx	create_julia_cplx(char *str_re, char *str_im)
{
	t_cplx	cplx;

	cplx.re = ft_atof_ld(str_re);
	cplx.im = ft_atof_ld(str_im);
	return (cplx);
}
