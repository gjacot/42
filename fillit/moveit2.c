/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:18:55 by gjacot            #+#    #+#             */
/*   Updated: 2016/02/12 18:59:18 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

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
	INIT(int, temp, 0);

	affiche(square);
	printf("\n\n");

	while (piece->next != NULL || ok == 0)
	{
		verif = verifsquare(square, piece);
		printf("movit - verif = %d\n", verif);
		if (verif == 0) // la piece est bonne on peu la placer sans se soucier de rien :)
		{
			placepiece(piece, square);
			moveit(piece = piece->next, square);
			
		}	
		else if (verif == 2 && piece->prev == NULL) //on supprime tout car on a tout tester et on agmente square
		{
			piece = mazpiece(piece, 0); //Mise A Zero de xy de chaque piece et retour a la premiere
			square = clearsquare(square, piece->lettre, (ft_strlen(square[0]) + 1)); //on agrandit le carrer
		}
		else if (verif == 2 && piece->prev != NULL) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
		{					//la piece ne rentre pas, on passe a la piece precedante
							// ATTENTION A piece->prev == NULL faut agrandir dans se cas la
			piece = piece->prev;
			temp = piece->x;
			piece = piece->next;
			clearsquare(square, piece->lettre, ft_strlen(square[0]));
			piece = mazpiece(piece, 2);//xy de la piece actuel est mize a zero et retour a la precedante
			piece->x = temp++;
		}
		else if (verif == 3) // y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		{		
			if ((int)ft_strlen(square[0]) > ((piece->x) + 1))
				piece->x++;
			else if ((int)ft_strlen(square[0]) > ((piece->y) + 1))
			{
				piece->x = 0;
				piece->y++;
			}
			else
			{
				piece = piece->prev;
				temp = piece->x;
				piece = piece->next;
				mazpiece(piece, 1);
				clearsquare(square, piece->lettre, ft_strlen(square[0]));
				printf("lettre = %c\n", piece->lettre);
				piece->x = temp++;
			}
		}
		else if (verif == 4) // y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		{
			piece->x = 0;
			piece->y++;
		}
		//nbrpiece = 0; //a suppr c'est pour le test
		if (piece->next == NULL)
			ok = 1;
	}
	return (square);
}