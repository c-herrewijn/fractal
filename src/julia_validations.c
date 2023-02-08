/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia_validations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 19:13:05 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 11:23:38 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* validates the string contains "2", optionally followed by a point and an 
* arbitrary number of zeros
*/
int	is_two(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != '2')
			return (0);
		else if (i == 1 && str[i] != '.')
			return (0);
		else if (i > 1 && str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

// validates that the string is a valid number in range [0.0, 2.0]
int	is_valid_range_abs(char *str)
{
	int	i;

	if (is_two(str))
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != '0' && str[i] != '1')
			return (0);
		else if (i == 1 && str[i] != '.')
			return (0);
		else if (str[i] == '.' && (i != 1))
			return (0);
		else if (!ft_isdigit(str[i]) && str[i] != '.' )
			return (0);
		i++;
	}
	return (1);
}

/* 
/ validates that nr of significant digits in the string fit in a long double
/ does NOT count leading zero's. 
/ Note: ignores all non numeric chars including '.'!
*/
int	is_valid_nr_decimals_ldbl(char *str)
{
	int	i;
	int	nr_decimals;

	i = 0;
	nr_decimals = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && str[i] != '0' && nr_decimals == 0)
			nr_decimals += 1;
		else if (ft_isdigit(str[i]) && nr_decimals > 0)
			nr_decimals += 1;
		i++;
	}
	if (nr_decimals > LDBL_DIG)
		return (0);
	return (1);
}

// validates input is in range [-2.0, 2.0] and digits fit in long double
int	is_valid_julia_coord(char *str)
{
	int	nr_decimals_valid;
	int	is_valid_range;

	if (str == NULL || str[0] == '\0')
		return (0);
	if (str[0] == '-')
		str += 1;
	is_valid_range = is_valid_range_abs(str);
	nr_decimals_valid = is_valid_nr_decimals_ldbl(str);
	return (nr_decimals_valid && is_valid_range);
}
