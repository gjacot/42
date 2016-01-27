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

void	moveit2(t_piece *piece, int taille)
{
	if (piece->next && piece->prev)
	{
		piece = piece->prev;
		piece->x++;
	}
	else
	{
		while (piece->prev)
		{
			taille++;
			piece = piece->prev;
		}
	}
}

void	moveit(t_piece *piece, int taille, char **square, int nbrpiece)
{
	int xy[2];
	int temp[2];
	int verif;
	int i;
	//printf("nbrpiece = %d\n", nbrpiece);
	while (nbrpiece > 0)
	{
		//printf("il rentre2\n");
		temp[0] = xy[0] = piece->x;
		temp[1] = xy[1] = piece->y;
		//printf("il rentre3\n");
		printf("square[0] moveit = %s\n", square[0]);
		printf("taille moveit = %d\n", taille);
		verif = verifsquare(square, taille, piece->piece, xy);
		printf("verif = %d\n", verif);

		if (verif == 0)
		{
			i = 0;
			
			while (i < 15)
			{
				/*printf("i = %d\n", i);
				printf("%c\n", piece->piece[i]);

				printf("xy[0] = %d\nxy[1] = %d\n", xy[0], xy[1]);
*/
				square[temp[1]][temp[0]] = piece->piece[i];

				i++;
				temp[0]++;
				if (i % 4 == 0)
				{
					temp[1]++;
					temp[0] -= 5;
				}
				
			}

			if (piece->next)
			{
				piece = piece->next;
				nbrpiece--;
			}
		}
		else if (verif == 1)
		{	piece->x = 0;
			piece->y++;
			
		}
		else if (verif == 2)
		{
			moveit2(piece, taille);
			square = clearsquare(square, piece->lettre, taille);
			moveit(piece, taille, square, nbrpiece);
		}
		else if (verif == 3)
			piece->x++;
		nbrpiece--;
	}
}

