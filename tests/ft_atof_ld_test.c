#include "float.h"
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		s++;
		c++;
	}
	return (c);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}

// validates that nr of digits fit in long double
static int	is_valid_nr_decimals_ldbl(char *str)
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

/* 
* converts a string to a long double
* assumes the input string is already validated!
*/
long double ft_atof_ld(char *str)
{
	long double ld_int_part;
	long double ld_fract_part;
	int i;

	ld_int_part = 0.0l;
	ld_fract_part = 0.0l;
	i = (str[0] == '-');
	while(str[i] != '\0' &&
		(ft_strchr(str, '.') == NULL || str+i < ft_strchr(str, '.')))
	{
		ld_int_part *= 10.0l;
		ld_int_part += ((long double)(str[i] - '0'));
		i++;
	}
	i = ft_strlen(str) - 1;
	while(ft_strchr(str, '.') != NULL && i>=0 && (str+i) > ft_strchr(str, '.'))
	{
		ld_fract_part += ((long double)(str[i] - '0'));
		ld_fract_part /= 10.0l;
		i--;
	}
	return ((long double)(1 - 2 * (str[0] == '-'))
		* (ld_int_part + ld_fract_part));
}

int main (void)
{
	long double long_double;

	printf("long double: %.25LF\n", ft_atof_ld("1.34"));
	printf("long double: %.25LF\n", ft_atof_ld("-1.34"));
	printf("long double: %.25LF\n", ft_atof_ld("12.34"));
	printf("long double: %.25LF\n", ft_atof_ld("987.34"));
	printf("long double: %.25LF\n", ft_atof_ld("0.0000000123"));
	printf("long double: %.25LF\n", ft_atof_ld("0.00000001"));
	printf("long double: %.25LF\n", ft_atof_ld("-0.00000001"));
	printf("long double: %.25LF\n", ft_atof_ld("100000001"));
	printf("long double: %.25LF\n", ft_atof_ld("123456789123456789"));
	printf("long double: %.25LF\n", ft_atof_ld("1234567891234567891"));
	printf("long double: %.25LF\n", ft_atof_ld("12345678912345678912"));
	printf("double1: %.25f\n", (double)ft_atof_ld("12345678912345678912"));
	printf("double2: %.25F\n", (double)ft_atof_ld("12345678912345678912"));
	printf("atof: %.25f\n", atof("12345678912345678912"));
}
