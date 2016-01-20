#include <stdio.h>
#include <stdlib.h>

int	my_free(void *addr)
{
	free(addr);
	return (1);
}

int	main()
{
	char	*str = malloc(sizeof(char));
	if (my_free(str))
		printf("It's wooork!!\n");
	return (0);
}
