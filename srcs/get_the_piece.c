/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_coordone		*create_coordone(void)
{
	t_coordone	position;

	if (!(position = (t_coordone*) malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = 0;
}

t_tertriminos	*create_tetriminos(int id)
{
	t_tetriminos	*piece;

	if (!(piece = (t_teriminos*)malloc(sizeof(t_teriminos))))
		return (NULL);
	if (!(piece->dim = create_coordone()) || !(piece->pos = create_coordone()))
		return (NULL);
	piece->id = id + 'A';
	piece->valu = 0;
	piece->pos->x = 8;
	piece->pos->y = 8;
	piece->next = 0;
	piece->prev = 0
	return (piece);
}

t_tetriminos	*tetris_push_front(t_tetriminos *begin, t_tetriminos elem)
{
	t_tetriminos	*t_elem;

	if (begin)
	{
		t_elem = begin;
		while (t_elem->next)
			t_elem = t_elem->next;
		t_elem->next = elem;
		elem->prev = t_elem;
	}
	else
		return (elem);
}

int				first_case(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (-1);
		if (i % 5 != 4 && str[i] == '#')
			return (i);
		else if (i % 5 != 4 && str[i] != '.')
			return (-1);
		i++;
	}
	return (i);
}

void			actual_mini_maxi(t_tetriminos *tetri, int i)
{
		if ((i % 8) < pos->x)
			pos->x = i % 8;
		if ((i / 8) < pos->y)
			pos->y = i / 8;
		if ((i % 8) > dim->x)
			dim->x = i % 8;
		if ((i / 8) > dim->y)
			dim->y = i / 8;
}

int				error(int mode)
{
	static	int	error = 0;

	if (mode & INIT)
		return (error = 0);
	if (mode & SET)
		return (error = 1);
	if (mode & GET)
		return (error);
}

void			search_the_diese(char *piece, t_tetriminos *tetri, int *nb, int i)
{
	unsigned	long	unite;

	unite = 1;
	if (piece[i] == '#')
	{
		piece[i] = '.';
		*tetri->valu += unite << (i % 5 + ((i / 5) * 8) );
		*nb += 1;
		actual_mini_maxi(tetri, i);
		if (i - 5 >= 0)
			search_the_diese(piece, val, nb, i - 5);
		if ((i - 1 ) % 5 != 4)
			search_the_diese(piece, val, nb, i - 1);
		if ((i + 1 ) % 5 != 0 && (i + 1) % 5 != 4)
			search_the_diese(piece, val, nb, i + 1);
		if (i + 5 < 20)
			search_the_diese(piece, val, nb, i + 5);
	}
	else if (piece[i] != '.')
		tetri->id = 0;
}

int				style_alive(str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			return (1);
	}
	return (0);
}

void				tetris_define_type(t_teriminos *t_elem)
{
	int			type_max;
	t_teriminos	*tetri;

	type_max = 1;
	tetri = t_elem;
	while (tetri->valu != t_elem->valu)
	{
		if (tetri->type > type_max)
			type_max = tetri->type;
		tetri = tetri->prev;
	}
	if (tetri)
		t_elem->type = tetri->type;
	else
		t_elem->type = type_max << 1;
}

void			finished_tetriminos(t_tetriminos tetri)
{
	tetri->dim->x = tetri->dim->x - tetri->pos->x;
	tetri->dim->y = tetri->dim->y - tetri->pos->y;
	tetri->valu  = tetri->valu >> (tetri->pos->x + (tetri->pos->y * 8));
	tetri->pos->x = 0;
	tetri->pos->y = 0;
	tetris_define_type(tetri);
}

int				my_free(void *addr)
{
	free(addr);
	return (1);
}

t_tetriminos	*get_next_piece(int fd, int id)
{
	t_tetriminos	*tetri;
	int				oct_lu;
	char			str[20];

	if (!(tetri = create_tetriminos(id)) && error(SET))
		return (NULL);
	if ((oct_lu = read(fd, str, 20)) != 20 && error(SET) && my_free(tetri) + 1)
		return(NULL);
	oct_lu = 0;
	search_the_diese(str, tetri, &oct_lu, first_case(str));
	if ((tetri->id == 0 || oct_lu != 4 || style_alive(str)) && error(SET)
	&& my_free(tetri) + 1)
		return (NULL);
	finished_tetriminos(tetri);
	return (tetri);
}

t_list			*get_the_pieces(int fd)
{
	t_tetriminos	*tetri;
	int				i;
	char			c;
	int				oct_lu;

	i = 0;
	error(INIT);
	tetri = ft_create_elem(get_next_piece(fd), i);
	oc_lu = read(fd, &c, 1);
	while (++i < 26 && oct_lu && c == '\n')
	{
		tetri = tetris_push_front(tetri, get_next_piece(fd, i));
		oct_lu = read(fd, &c, 1);
	}
}

void			generate_order(t_tetriminos tetri, int size, int indice)
{
	int	i;

	i = 0;
	while (i < (size - indice))
	{
	}
}

int				fillit_structure()
{
}
