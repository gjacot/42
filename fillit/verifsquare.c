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

int		verifsquare(char **square, t_piece *piece)
{
	int i;
	int x;
	int y;
	int len;
	len = ft_strlen(square[0]);
	i = 0;
	
	x = piece->x;
	y = piece->y;
	printf("verifsquare - len = %d\n", len);

	printf("verifsquare - piece = %s\n", piece->piece);

	printf("verifsquare - BOUCLE\n\n\n");
	
	while (i < 15) //pour tout tab
	{
	printf("verifsquare - i = %d\n", i);
	printf("verifsquare - x = %d\n", x);
	printf("verifsquare - y = %d\n", y);
		if ((x >= len) || (i % 4 == 0))//pour changer de dimension dans square car square = char** et piece->piece = char *
		{
			printf("verifsquare - DEBUT 1er if\n");
			x = piece->x; //reinitialise x au coords de depart.
			y++;
			printf("verifsquare - x = %d\n", x);
			printf("verifsquare - y = %d\n", y);
			printf("verifsquare - FIN 1er if\n");
		}

		if (y >= len) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas) 
		{				//oublie du = car len commance a 1 et y a 0
			printf("verifsquare - y >= len \n");
			return (2); //la piece ne rentre pas, on passe a la piece precedante
		}
			

		if (piece->piece[i] != '.') //ne s'occupe que des pieces deja presente 
		{
			printf("verifsquare - DEBUT 3er if\n");
			printf("verifsquare - x = %d\n", x);
			printf("verifsquare - y = %d\n", y);
			if (square[y][x] != '.') //c'est cette PUTAIN de ligne qui fait chier car il test y = 3 et x = 0
			{
			printf("verifsquare - x2 = %d\n", x);
			printf("verifsquare - y2 = %d\n", y);
				return (3); //supperposition
			}
			printf("verifsquare - FIN 3er if\n");
		}
		i++;
		x++;
			printf("verifsquare - x = %d\n", x);
	printf("verifsquare - y = %d\n", y);
		printf("verifsquare - BOUCLE2\n\n");
	}
	//on peu placer la piece ici sinon
	printf("verifsquare - FIN BOUCLE\n\n\n");
	return (0);
}
