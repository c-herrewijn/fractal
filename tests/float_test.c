# include "../sources/fractol.h"
// gcc float_test.c ../sources/julia_validations.c ../libft/ft_isdigit.c

int	is_valid_nr_decimals_ldbl(char *str);
int	is_valid_range_abs(char *str);
int	is_two(char *str);

int main(void)
{
	// puts("testing is_two");
	// printf("%d - 1\n", is_two("2"));
	// printf("%d - 1\n", is_two("2.000"));
	// printf("%d - 0\n", is_two("1.9"));
	// printf("%d - 0\n", is_two("3"));
	// printf("%d - 0\n", is_two("2..0"));
	// printf("%d - 0\n", is_two("2.."));
	// printf("%d - 0\n", is_two("-2"));
	
	// puts("testing is_valid_range_abs");
	// printf("%d - 1\n", is_valid_range_abs("0"));
	// printf("%d - 1\n", is_valid_range_abs("0.0"));
	// printf("%d - 1\n", is_valid_range_abs("0.5"));
	// printf("%d - 1\n", is_valid_range_abs("1.5"));
	// printf("%d - 1\n", is_valid_range_abs("2.0"));
	// printf("%d - 0\n", is_valid_range_abs("2.5"));
	// printf("%d - 0\n", is_valid_range_abs(".5"));
	// printf("%d - 0\n", is_valid_range_abs("1..5"));
	// printf("%d - 0\n", is_valid_range_abs("10.5"));
	// printf("%d - 0\n", is_valid_range_abs("2.5"));
	
	// puts("testing is_valid_nr_decimals_ldbl");
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("0.0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("0.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("1.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("2.0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("2.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-0.0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-0.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-1.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-2.0"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-2.5"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("1.23456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("1.234567890123456789"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-1.23456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("-1.234567890123456789"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("0.123456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("0.1234567890123456789"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-0.123456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("-0.1234567890123456789"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("0.00000123456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("0.000001234567890123456789"));
	// printf("%d - 1\n", is_valid_nr_decimals_ldbl("-0.00000123456789012345678"));
	// printf("%d - 0\n", is_valid_nr_decimals_ldbl("-0.000001234567890123456789"));

	puts("testing is_valid_julia_coord");
	printf("%d - 0\n", is_valid_julia_coord(""));
	printf("%d - 0\n", is_valid_julia_coord("0a"));
	printf("%d - 0\n", is_valid_julia_coord(".1"));
	printf("%d - 1\n", is_valid_julia_coord("0.0"));
	printf("%d - 1\n", is_valid_julia_coord("0.5"));
	printf("%d - 1\n", is_valid_julia_coord("1.5"));
	printf("%d - 1\n", is_valid_julia_coord("2"));
	printf("%d - 1\n", is_valid_julia_coord("2.00"));
	printf("%d - 1\n", is_valid_julia_coord("-2.00"));
	printf("%d - 0\n", is_valid_julia_coord("2.5"));
	printf("%d - 0\n", is_valid_julia_coord("--1"));
	printf("%d - 1\n", is_valid_julia_coord("-0"));
	printf("%d - 1\n", is_valid_julia_coord("-0.0"));
	printf("%d - 1\n", is_valid_julia_coord("-0.5"));
	printf("%d - 1\n", is_valid_julia_coord("-1.5"));
	printf("%d - 1\n", is_valid_julia_coord("-2.0"));
	printf("%d - 0\n", is_valid_julia_coord("-2.5"));
	printf("%d - 1\n", is_valid_julia_coord("1.23456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("1.234567890123456789"));
	printf("%d - 1\n", is_valid_julia_coord("-1.23456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("-1.234567890123456789"));
	printf("%d - 1\n", is_valid_julia_coord("0.123456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("0.1234567890123456789"));
	printf("%d - 1\n", is_valid_julia_coord("-0.123456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("-0.1234567890123456789"));
	printf("%d - 1\n", is_valid_julia_coord("0.00000123456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("0.000001234567890123456789"));
	printf("%d - 1\n", is_valid_julia_coord("-0.00000123456789012345678"));
	printf("%d - 0\n", is_valid_julia_coord("-0.000001234567890123456789"));
	printf("%d - 0\n", is_valid_julia_coord("1.0000012345678901234567"));
}