# include "header.h"

int				ft_tetrilen(t_tetriminos *begin)
{
	short				i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i - 1);
}
