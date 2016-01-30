/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_resulte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 07:36:32 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_sqare	*ft_create_square()
{
	t_sqare	*ground;
	int		i;
	int		j;

	ground = (t_sqare*)malloc(sizeof(t_sqare));
	if (!ground)
		return (NULL);
	ground->area = (unsigned long **)malloc(sizeof(unsigned long *) * 2);
	if (!ground->area)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		j = -1;
		ground->area[i] = (unsigned long *)malloc(sizeof(unsigned long) * 2);
		if (!ground->area[i])
			return (NULL);
		while (++j < 2)
			ground->area[i][j] = 0;
		i++;
	}
	ground->dim = 0;
	return (ground);
}

unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos
					, unsigned long horizontal, unsigned long vertical)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;
	int					i;

	mh = 0;
	mv = 0;
	i = 0;
	while (i < pos->x)
	{
		mv |= vertical << i;
		i++;
	}
	i = 0;
	while (i < pos->y)
	{
		mh |= horizontal << (i * 8);
		i++;
	}
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (pos->x + (8 * pos->y)));
	ecr |= (((gr->area[0][1] & ~mv & mh) >> pos->x) << (8 * (8 - pos->y)));
	ecr |= (((gr->area[1][0] & mv & ~mh) << (8 - pos->x)) >> (8 * (pos->y)));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - pos->x) + (8 * (8 - pos->y))));
	return (ecr);
}

t_sqare	*glb_ground(int mode, t_sqare *value)
{
	static	t_sqare	ground;

	if (mode & GET)
		return (ground);
	else if (mode & SET)
		return (ground = value);
	else
		return (NULL);
}

unsigned	long	*ft_init_windows(t_coordone *pos)
{
	int					i;
	unsigned	long	windows[3];
	t_sqare				*ground;
	int					nb_win;

	ground = glb_ground(GET, 0);
	nb_win = (ground->dim <= 12) ? 2 : 3;
	nb_win = (ground->dim <= 8) ? 1 : nb_win;
	pos = create_coordone(pos->y);
	i = 0;
	while (i < nb_win)
	{
		pos->x = (i * 4);
		windows[i] = ft_working_window(ground, pos, HORIZONTAL, VERTICAL);
		i++;
	}
	free(pos);
}

int	ft_push_tetriminos(t_tetriminos elem)
{
	t_coordone			pos;
	unsigned	long	wimdows[3];
	int					i;

	i = 0;
	pos = create_coordone();
	windows = ft_init_windows(pos);
	while (pos->x < 8 - elem->dim->x)
	{
		if (elem->value & windows[i] == 0)
		{
			// on actualise le ground
			free(pos);
			return (1);
		}
		elem->valu <<= 1;
		(pos->x)++;
	}
	free(pos);
	return (0);
}

/*
AJOIUTER UNE PIECE
	-Il faut stoquer le tableau dans un singleton mais garder 
	l'adresse en memoir.
nb ecr:
	1 si dim <= 8
	2 si dim <= 12
	3 si dim <= 16

	-on les renouvelle quand on a fini
largeur de travaille = 8 - largeur de la piece
01234567 89ABCDEF
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........

12 = 2*6 
12 = 3*4
12 = 4*3
12 = 1*12

26*4




AAAABBBBCCCC
DDDDEEEEFFFF
GGGGHHHHIIII
JJJJKKKKLLLL
MMMMNNNNOOOO
PPPPQQQQRRRR
SSSSTTTTUUUU
VVVVWWWWXXXX
YYYYZZZZ....
............
............
............


01234567 | 456789ABCD


*/
