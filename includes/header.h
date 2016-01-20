/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADEr_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define ERROR
# define INIT 1
# define SET 2
# define GET 4

typedef	struct			s_list;
{
	struct	s_list		*next;
	void				*data;
}						t_list

typedef	struct			s_coordone
{
	int					x;
	int					y;
}						t_coordone;

typedef	struct			s_tetriminos;
{
	unsigned	long	valu;
	char				id;
	int					type;
	t_coordone			*dim;
	t_coordone			*pos;
}						t_tetrimonos;

typedef					s_plateau
{
	t_list				*pieces;
	int					taille;

}						t_plateau;
#endif


//	1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256

//	RECUPERER LES PIECE:
//		-on fait un read de 20
//			-si il echou => erreur
//		-on cherche le premier '#'
//		-on lance l'ago de recherche_connex/supression
//			-on enregistre les case dans un double
//			-on stoque x_min/x_max y_min\y_max
//			-si : nb_case != 4 || len(ligne) != 4 || mauvais char
//				=> erreur
//		-on cherche j'usqu'a la fin si il reste des '#' (on a suprimer ceux lu)
//		-on decale le plus en haut et le plus a gauche;
//		-on lui assigne une id en fontion de l'ordre darriver (maj dan l'ordre)
//		-on lui assigne un type:
//			-un nouveau si la piece est unique, sinon le meme que celle identique
//		
//		-si il y a un '\n' on recomence


//	Le PLATEU:
//		-recuperer un ecran a partir de coordone
//		
//

//	ALGO RECHERCHE:
//		-generer les different ordre recurivement en evitant les doublon
//		-on definie une taille minimale de carre
//		-
//		
