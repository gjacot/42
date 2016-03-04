/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:59:52 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/04 18:39:57 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>


//CE PUTAIN DE FILLIT ME SAOULE !!!

t_piece	*mazpiece(t_piece *piece, int cond)
{
	//piece actuel si il y en a qu'une
	piece->x = 0;
	piece->y = 0;
	if (cond == 0)
	{
		//remettre x et y sur toute les piece a zero
		while (piece->next != NULL)
			piece = piece->next; //va tout a la fin pour faire toutes les piece
		while (piece->prev != NULL)
		{
			piece->x = 0;
			piece->y = 0;
			piece = piece->prev;
		}
		//piece est la premiere piece
		printf("mazpiece 1 OK\n");
	}
	else if (cond == 1)
	{
		if (piece->prev != NULL)
			piece = piece->prev;
		printf("mazpiece 2 OK\n");
	}
	return (piece);
}

void placepiece(t_piece *piece, char **square)
{
	printf("square = %p\n", square);
	printf("piece = %p\n", piece);
	INIT(int, i, 0);
	INIT(int, compteur, 0);

	while (i < 15 && compteur < 4)
	{
		if (piece->piece[i] != '.')
			compteur++;
		if (square[piece->y][piece->x] != '\0' && piece->piece[i] != '.')
			square[piece->y][piece->x]  = piece->piece[i];
		i++;
		piece->x++;
		if (i % 4 == 0)
		{
			piece->y++;
			piece->x -= 4; //c'est 4 !
		}
	}
}

char	**moveit(t_piece *piece, char **square)
{
	int verif;

	INIT(int, ok, 0);
	INIT(int, ok2, 0);
	INIT(int, ok3, 0);

	affiche(square);
	printf("\n\n");


	if (ok == 1)
		return (square);
while (ok3 == 0)
{

	verif = verifsquare(square, piece);
	printf("movit - verif = %d\n", verif);
	if (verif == 0)
	{
	// la piece est bonne on peu la placer sans se soucier de rien :)
		placepiece(piece, square);
		ok3 = 1;
		square = moveit(piece->next, square);
	}


	else if (verif == 2 && piece->prev == NULL && ok2 == 0)
	{
	//on supprime tout car on a tout tester et on agmente square
	//y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
	//la piece ne rentre pas, on passe a la piece precedante
	// ATTENTION A piece->prev == NULL faut agrandir dans se cas la
		piece = mazpiece(piece, 0);
		square = clearsquare(square, 'A', (ft_strlen(square[0]) + 1));
		ok2 = 1;
		
	}


	else if (verif == 2 && piece->prev != NULL)
	{
	//on supprime tout car on a tout tester et on agmente square
	//y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
	//la piece ne rentre pas, on passe a la piece precedante
	// ATTENTION A piece->prev == NULL faut agrandir dans se cas la
	
	}


	else if (verif == 3)
	{
	// y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		if ((int)ft_strlen(square[0]) > ((piece->x) + 1))
			piece->x++;
		else if ((int)ft_strlen(square[0]) > ((piece->y) + 1))
		{
			piece->x = 0;
			piece->y++;
		}
		else
		{
			piece->x = 0;
			piece->y = 0;
			clean(square,piece->lettre);
			square = moveit(piece->prev, square);
		}
	}


	else if (verif == 4)
	{
	// y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
			piece->x = 0;
			piece->y++;
	}
	if (piece->next == NULL)
		ok = 1;
}
	
	return (square);
}

















