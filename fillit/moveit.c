/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:18:55 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/27 18:22:46 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

t_piece	*mazpiece(t_piece *piece, int cond)
{
	if (cond == 0)
	{
		//piece actuel si il y en a qu'une
		piece->x = 0;
		piece->y = 0;
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
		printf("mazpiece OK\n");
	}
	else if (cond == 1)
	{
			piece->x = 0;
			piece->y = 0;
			if (piece->prev != NULL)
				piece = piece->prev;
	}
	return (piece);
}

char	**moveit(t_piece *piece, char **square, int nbrpiece)
{
//	piece = NULL;
//	square = NULL;
//	nbrpiece = 0;
	
	printf("---DEBUT MOVIT---\n");
	printf("movit - nbrpiece = %d\n", nbrpiece);
	int xy[2];
	int temp[2];
	int verif;
	int i;
	int ok;
	int compteur;
	int savenbrpiece = nbrpiece;

	i = 0; 
	ok = 0;
	printf("movit - affiche(square)\n");
	affiche(square);
	printf("movit - fin affiche(square)\n");

	while (piece->next != NULL || ok == 0) 
	{

	printf("movit - nbrpiece = %d\n", nbrpiece);

		temp[0] = xy[0] = piece->x;
		temp[1] = xy[1] = piece->y;
		verif = verifsquare(square, piece);
		//verif = 3;
		printf("movit - verif = %d\n", verif);


////////
		if (verif == 0) // la piece est bonne on peu la placer sans se soucier de rien :)
		{
			i = 0;
			printf("---JOHAN---\n");
			affiche(square);
			printf("johan - piece = %s\n", piece->piece);
			temp[1]--;
			compteur = 0;
			while (i < 15 && compteur <= 3)
			{
			printf("johan - i = %d\n", i);
			printf("johan - temp[y] = %d\n", piece->y);
			printf("johan - temp[x] = %d\n", piece->x);
			printf("johan - piece[%d] = %c\n", i, piece->piece[i]);
			printf("johan - square[%d][%d] = %c\n", piece->y, piece->x, square[piece->y][piece->x]);
			if (piece->piece[i] != '.')
				{
					compteur++;
					printf("moveit - compteur = %d\n", compteur);
					
				}
			if (square[piece->y][piece->x] != '\0' && piece->piece[i] != '.')
				square[piece->y][piece->x]  = piece->piece[i];

			printf("johan - square[%d][%d] = %c\n", piece->y, piece->x, square[piece->y][piece->x]);
				i++;
				piece->x++;
				if (i % 4 == 0)
				{
					piece->y++;
					piece->x -= 4; //c'est 4 !
				}

				
			}
			if (piece->next != NULL)
			{
				piece = piece->next;
			}

			
			printf("movit - nbrpiece = %d\n", nbrpiece);
			nbrpiece--;
			printf("movit - nbrpiece = %d\n", nbrpiece);
			affiche(square);
			printf("---FIN JOHAN---\n");
		}
 

/////////
		else if (verif == 2 && piece->prev == NULL) //on supprime tout car on a tout tester et on agmente square
		{
			piece->x = 0;
			piece->y = 0;
			piece = mazpiece(piece, 0); //Mise A Zero de xy de chaque piece
			printf("pointeur square2 = %p\n", square);
			ft_putstr(square[0]);
			printf("lettre = %c\n", piece->lettre);
			printf("ft_strlen(square[0]) = %zu\n", ft_strlen(square[0]));
			square = clearsquare(square, piece->lettre, (ft_strlen(square[0]) + 1)); //on agrandit le carrer
			printf("pointeur square3 = %p\n", square);
			//ft_putstr(square[0]);
			//moveit(piece, square, nbrpiece); //square est maintenant plus grand
		}
///////
		else if (verif == 2 && piece->prev != NULL) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
		{					//la piece ne rentre pas, on passe a la piece precedante
							// ATTENTION A piece->prev == NULL faut agrandir dans se cas la
			nbrpiece++;
			clearsquare(square, piece->lettre, ft_strlen(square[0]));
			piece = mazpiece(piece, 1);//xy de la piece actuel est mize a zero
		}

		else if (verif == 3) // y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		{
			if ((int)ft_strlen(square[0]) > ((piece->x) + 1))
			{
				
				piece->x++;
				printf("movit - verif 3.1 - x = %d\n", piece->x);
			}
			else
			{
				piece->x = 0;
				piece->y++;
				printf("movit - verif 3.2 - y = %d\n", piece->y);
			}
		}
		else if (verif == 4) // y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		{
			
				piece->x = 0;
				piece->y++;
				printf("movit - verif 4.1 - y = %d\n", piece->y);
			
		}
		//nbrpiece = 0; //a suppr c'est pour le test
		ok = 1;
		if (nbrpiece > (savenbrpiece + 1))
			error2("Error trop de nbrpiece\n", 2);
	}
	return (square);
}

