/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 07:36:32 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_RESULT_H
# define SQUARE_RESULT_H

# define GET 1
# define SET 2
# define NB_WINDOWS 4


typedef	struct			s_square
{
	unsigned	long	**area;
	int					dim;
}						t_sqare;
#endif

//	initialisation du tableau---------------------------------->	DONE
//	incrementation de la taille du taleau						
//	calcule du plus petit carre possible						
//	recuperer une ecran de travail----------------------------->	DONE
//	decaler l'ecran de travail									
//	placer une piece dans le tableau							
//		-la placer dans l'ecran de travail
//		-ecrire l'ecran dans le tableau
//	retirer une piece du tableau
//		-on cheque sur quel area elle est presente
//		-on genere des masque pour chaque area
//		-on relance lecran
//	creation du resultat
//	decalage de la premier case si pas de solution
//	liberation de toute la memoire
//	detection des case vide
//		-index par type de la dernier place emprinter
//		-recherche de zone vide puis matchage avec les piece


//	OPTIMISATION
//		-garder en memoir tout les masque possible
//		-n'utiliser que des masque verticale (cas particulier?)
//		-garder en memoir 2 ou 3 ecran ded travaille pour les fin de ligne

//	eran:
//	on va fionalement utiliser des eccran superposer:
//	la taille maximum c'est 



