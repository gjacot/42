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

void	mazpiece(t_piece *piece, int cond)
{
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
	}
	else if (cond == 1)
	{
			piece->x = 0;
			piece->y = 0;
			if (piece->prev != NULL)
				piece = piece->prev;
	}
}

void	moveit(t_piece *piece, char **square, int nbrpiece)
{
	int xy[2];
	int temp[2];
	int verif;
	int i;

	i = 1; 
	while (nbrpiece > 0) 
	{
		temp[0] = xy[0] = piece->x;
		temp[1] = xy[1] = piece->y;
		verif = verifsquare(square, piece);
		printf("verif = %d\n", verif);


////////
		if (verif == 0) // la piece est bonne on peu la placer sans se soucier de rien :)
		{
			
			
			while (i < 15)
			{
				square[temp[1]][temp[0]] = piece->piece[i];

				i++;
				temp[0]++;
				if (i % 4 == 0)
				{
					temp[1]++;
					temp[0] -= 4;
				}
				
			}

			if (piece->next != NULL)
			{
				piece = piece->next;
				nbrpiece--;
			}
		}


/////////
		else if (verif == 2 && piece->prev == NULL) //on supprime tout car on a tout tester et on agmente square
		{
			nbrpiece++;
			piece->x = 0;
			piece->y = 0;
			mazpiece(piece, 0); //Mise A Zero de xy de chaque piece
			square = clearsquare(square, piece->lettre, ft_strlen(square[0] + 1)); //on agrandit le carrer
			moveit(piece, square, nbrpiece); //square est maintenant plus grand
		}
///////
		else if (verif == 2 && piece->prev != NULL) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
		{					//la piece ne rentre pas, on passe a la piece precedante
							// ATTENTION A piece->prev == NULL faut agrandir dans se cas la
			nbrpiece++;
			clearsquare(square, piece->lettre, ft_strlen(square[0]));
			mazpiece(piece, 1);//xy de la piece actuel est mit a zero et retour a la piece precedante
		}

		else if (verif == 3) // y a une supperposition, on peu tester a x++; en faisant gaffe a la taille de square sinon y++ et x = 0;
		{
			if ((int)ft_strlen(square[0]) > ((piece->x) + 1))
			{
				piece->y++;
				piece->x = 0;
			}
		}
	//	nbrpiece = 0; //a suppr c'est pour le test
	}
}

