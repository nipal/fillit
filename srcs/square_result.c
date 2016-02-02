/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_resulte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/03 00:49:55 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HORIZONTAL 255
#define VERTICAL 72340172838076673

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

unsigned	long	get_vertical_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			vertical;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		vertical = VERTICAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= vertical << i;
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

unsigned	long	get_horizontal_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			horizontal;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		horizontal = HORIZONTAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= horizontal << (i * 8);
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos
					, unsigned long horizontal, unsigned long vertical)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;

	mh = get_horizontal_mask(pos->x);
	mv = get_horizontal_mask(pos->y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (pos->x + (8 * pos->y)));
	ecr |= (((gr->area[0][1] & ~mv & mh) >> pos->x) << (8 * (8 - pos->y)));
	ecr |= (((gr->area[1][0] & mv & ~mh) << (8 - pos->x)) >> (8 * (pos->y)));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - pos->x) + (8 * (8 - pos->y))));
	return (ecr);
}

int		glb_nb_windows(int mode, int sqr_dim)
{
	static	int	nb_windows = 1;

	if (mode & GET)
		return (nb_windows);
	else if (mode & SET)
	{
		nb_windows = (sqr_dim <= 12) ? 2 : 3;
		nb_windows = (sqr_dim <= 8) ? 1 : nb_windows;
		return (nb_windows);
	}
	else
		return (1);
}

int		glb_sqr_dim(int mode, int value)
{
	static	int	sqr_dim = 1;
	t_sqare		*ground;

	if (mode & GET)
		return (sqr_dim);
	else if (mode & SET)
	{
		ground = glb_ground(GET, 0);
		ground->dim = value;
		glb_nb_windows(SET, value);
		sqr_dim = value;
		return (sqr_dim);
	}
	else
		return (1);
}

t_sqare	*glb_ground(int mode, t_sqare *value)
{
	static	t_sqare	ground;

	if (mode & GET)
		return (ground);
	else if (mode & SET)
	{
		ground = value;
		glb_sqr_dim(SET, ground->dim);
		return (ground);
	}
	else
		return (NULL);
}

unsigned	long	*ft_init_windows(t_coordone *pos, int stage)
{
	int					i;
	unsigned	long	windows[3];
	t_sqare				*ground;
	int					nb_win;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	pos = create_coordone_y(stage * 4);
	i = 0;
	while (i < nb_win)
	{
		pos->x = (i * 4);
		windows[i] = ft_working_window(ground, pos, HORIZONTAL, VERTICAL);
		i++;
	}
	free(pos);
	return (wimdows);
}

int		ft_resting_posx(t_tetriminos *elem, int i)
{
	elem->valu >>= (8 - elem->dim->x);
	elem->pos->x = 0;
	return (i);
}

int		ft_resting_posy(t_tetriminos *elem, int j)
{
	elem->valu >>= ((8 - elem->dim->y) * 8);
	elem->pos->y = 0;
	return (j);
}


void	ft_set_tetris(t_tetriminos *elem, t_coordone *pos)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	pos->x *= 4;
	pos->y *= 4;
	mv = get_vertical_mask(pos->x);
	mh = get_horizontal_mask(pos->y);
	gr->area[0][0] |= (elem->value & ~mh & ~mv) >> (pos->x + (8 * pos->y));
	gr->area[0][1] |= ((elem->value & ~mh & mv) >> pos->x) << (8 * (8 - pos->y));
	gr->area[1][0] |= ((elem->value & mh & ~mv) << (8 - pos->x)) >> (8 * pos->y);
	gr->area[1][1] |= (elem->value & mh & mv) << (8 - pos->x + (8 * (8 - pos->y)));
}


void	ft_remouve_tetris(t_tetriminos *elem)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_coordone			*pos;
	t_sqare				*gr;

	pos = create_coordone();

	gr = glb_ground(GET, 0);
	pos->x = (elem->pos->x / 4) * 4;
	pos->y = (elem->pos->y / 4) * 4;
	mv = get_vertical_mask(pos->x);
	mh = get_horizontal_mask(pos->y);
	gr->area[0][0] &= ~((elem->value & ~mh & ~mv) >> (pos->x + (8 * pos->y)));
	gr->area[0][1] &= ~(((elem->value & ~mh & mv) >> pos->x) << (8 * (8 - pos->y)));
	gr->area[1][0] &= ~(((elem->value & mh & ~mv) << (8 - pos->x)) >> (8 * pos->y));
	gr->area[1][1] &= ~((elem->value & mh & mv) << (8 - pos->x + (8 * (8 - pos->y))));
	free(pos);
}


//ft_tetrilen(t_tetriminos);

char	*ft_init_str_result()
{
	char	*reslut;
	int		len;
	int		i;

	len = glb_sqr_dim(GET, 0);
	len = len * (len + 1);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	resut[len] = '\0';
}

int	indice_input(t_coordone *pos, t_coordone *ind, int len)
{
	return ((indice->x + pos->x) + ((indice->y + pos->y) * len + 1));
}

char	*ft_get_result(t_coordone *pos, t_coordone *indice, t_tetriminos *elem, int len)
{
	static	char		*result = 0;
	static	int			init = 1;
	unsigned	double	unite;

	if (init)
		result = ft_init_str_result();
	unite = 1;
	while (indice->y < 4)
	{
		indice->x = 0;
		while (indice->x < 4)
		{
			if (elem->valu & unite << (indice->x + (8 * indice->y)))
				result[indice_input(pos, indice, len)] = elem->id;
			(indice->x)++;
		}
		(indice->y)++;
	}
	return (result);
}

void	ft_print_resut(t_tetriminos *begin)
{
	t_coordone			*pos;
	t_coordone			*indice;
	int					len;

	pos = create_coordone();
	indice = create_coordone();
	len= glb_sqr_dim(GET, 0);
	while (begin)
	{
		copy_coordone(pos, begin->pos);
		ft_resting_posx(begin, 0);
		ft_resting_posx(begin, 0);
		result = ft_get_result(pos, indice, begin, len);
		begin = begin->next;
	}
	ft_putsrt(result);
	free(pos);
	free(pos);
}
/*	IMPRIMER LES PIECE:
 *		-on sauvgard la position
 *		-on decale la piece en haut a gauche
 *		-on fait une boucle sur un carer de 4*4
 *			-on incremente a la bose position chaque piece;
 *
 * */


/*
   .
00 | 10
<- # ->
01 | 11
   .
*/

/*
 *	mask_v = get_vertical_mask(scr_pos->x * 4);
 *
 *
*/

void	ft_rm_tetriminos(t_tetriminos *elem)
{
	//	on deduis, a partir de la position, les ecran sur les quelle la piece enpiete
	//	on place des 0 au bon endroit avec  un OU EXCLUSIF
	//	on reset la position de la piece
}

int	ft_push_tetriminos(t_tetriminos *elem)
{
	t_coordone			indice;
	unsigned	long	wimdows[3];
	int					nb_windows;

	i = 0;
	pos = create_coordone();
	indice = create_coordone();
	nb_windows = glb_nb_windows(GET, 0);

	windows = ft_init_windows(0, indice->y);
	while (indice->y < nb_windows)
	{
		while ((elem->pos->y < 8 - elem->dim->y) && elem->pox->y + (4 * nb_windows) < glb_sqr_dim(GET, 0) - elem->dim->y)
		{
			while(indice->x < nb_windows)
			{
				while ((elem->pos->x < 8 - elem->dim->x) && elem->pox->x + (4 * nb_windows) < glb_sqr_dim(GET, 0) - elem->dim->x)
				{
					if (elem->value & windows[i] == 0)
					{
						ft_set_tetris(elem, indice);
						free(indice);
						return (1);
					}
					elem->valu <<= 1;
					(elem->pos->x)++;
				}
				ft_resting_posx(elem, (indice->x)++);
			}
			elem->valu <<= 8;
			(elem->pos->y)++;
		}
		ft_resting_posy(elem, (indice->y)++);
	}
	free(pos);
	return (0);
}
/*	ENLEVER UNE PIECE
 *
 *	c'est comme si on veux l'ajouter
 *	sauf que on veux ecrire des 0 au lieu d'ecrire des 1
 *
 *
 *
 * */

/*
AJOIUTER UNE PIECE
	-Il faut stoquer le tableau dans un singleton mais garder 
	l'adresse en memoir.
nb ecr:
	1 si dim <= 8
	2 si dim <= 12
	3 si dim <= 16
-on check sur la largeur
	-on peu switcher d'ecran
	-et revenir a la ligne (recalage de la piece)
-qund on a fini la hauteur des ecran on en regenere 3 autre
	-on reclae la piece tut comme il faut
	et on recomence
quand on a tout fini et que c'est nun on renvoir (0)

j < nb_ecr
{
	y < 8 - dim->y
	{
		i < nb_ecr
		{
			x < 8 - dim->x
			{
				x++
			}
			raz->x(ecr) && i++
		}
		y++
	}
	get_window();
	raz->y(ecr) && j++
}

(i,j) -> indice
(x,y) -> pos

CONVERSION (x(ecr) + i) => x(ground)
	- ground->x - (4 * indice->x) = ecr->x
	- ecr->x + (4 * indice->x) = ground->x
CONVERSION (y(ecr) + j) => y(ground)
	- ground->y - (4 * indice->y) = ecr->y
	- ecr->y + (4 * indice->y) = ground->y

+++++++++++++++++++++++++++++++
ou commencer sur un nouvelle ecran

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
