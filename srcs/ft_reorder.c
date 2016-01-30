# include "header.h"

void	ft_reorder(t_tetriminos *rabbit)
{
	t_tetriminos	*stick;
	t_tetriminos	*turtle;

	stick = rabbit;
	while (stick->next)
	{	
		rabbit = stick->next;
		turtle = stick;
		while (rabbit)
		{
			if (rabbit->id < turtle->id)
				turtle = rabbit;
			rabbit = rabbit->next;
		}
		if (turtle != stick)
		{
			ft_tetriswap(turtle, stick);
			stick = turtle->next;
		}
		else
			stick = stick->next;
	}
}

void	ft_tetriswap(t_tetriminos *r1, t_tetriminos *r2)
{
	t_tetriminos	*s;

	if (r1 && r2)
	{
		if (r1->prev)
			r1->prev->next = r2;
		if (r2->prev)
			r2->prev->next = r1;
		s = r1->prev;
		r1->prev = r2->prev;
		r2->prev = s;
		if (r2->next)
			r2->next->prev = r1;
		if (r1->next)
			r1->next->prev = r2;
		s = r1->next;
		r1->next = r2->next;
		r2->next = s;
	}
}