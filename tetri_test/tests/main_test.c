#include <stdio.h>

typedef unsigned long t_ul;

void print_long_bit(t_ul nbr)
{
	int		i;
	int		j;
	t_ul	unit;

	unit = 1; 
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (nbr & (unit << ((8 * i) + j)))
				printf("#");
			else
				printf(".");
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main()
{
	t_ul	var = 0;
	int		i;
	t_ul	unit;

	unit = 1;
	var = unit + (unit << 8) + (unit << 16) + (unit << 17);
	i = 0;
	while (i < 32)
	{
		print_long_bit(var);
		var = var << 1;
		printf("**************************************************\n");
		i++;
	}
	printf("nombre de bit d'un double : %ld\n", sizeof(double) * 8);
	printf("nombre de bit d'un long : %ld\n", sizeof(unsigned long) * 8);
	printf("nombre de bit d'un int : %ld\n", sizeof(unsigned int) * 8);
	return (0);
}
