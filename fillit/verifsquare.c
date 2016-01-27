/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:22:40 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/21 15:52:37 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libfillit.h>
#include <libft.h>

int		verifsquare(char **square, int taille, char *tab, int *coord)
{
	int i;
	int x;
	int y;

	i = 0;
	
	x = coord[0];
	y = coord[1];
	/*printf("x = %d --- y = %d\n", x, y);
	
		printf("%s\n", tab);*/
	while (i < 15) //pour tout tab
	{
		


		//printf("verifsquare i = %d\n", i);
		if (i % 4 == 0) //pour changer de dimension dans square
		{
		//	printf("dimension\n");
			y++;
			x = coord[0]; //reinitialise x au coords de depart.
		//	printf("y = %d\n", y);
			//printf("dimension2\n");
		}

		if ((y >= taille) && (x >= taille))
			return (1); //pas possible


		if (tab[i] != '.')
		{
		/*	printf("x + (i | 4) = %d   ", (x + (i % 4)));
			printf("taille = %d \n", taille);

			printf("(y + (i | 4) = %d   ", (y + (i % 4)));
			printf("taille = %d \n", taille);*/

			if ((x + (i % 4) >= taille) || (y + (i % 4) >= taille)) //a verif, pas sur avec y
				return (2); //supperieur a taille
			if (square[y][x + (i % 4)] != '.')
				return (3); //supperposition
		}
		i++;
		x++;
	}
	return (0);
}
