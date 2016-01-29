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

	/*printf("x = %d --- y = %d\n", x, y);
	
		printf("%s\n", tab);*/
	while (i < 15) //pour tout tab
	{
	
		if ((y >= len) && (x >= len))
			return (1); //la piece ne rentre pas, on passe a la piece precedante


		if ((x >= len) || (i % 4 == 0))//pour changer de dimension dans square car square = char** et piece->piece = char *
		{
			x = piece->x; //reinitialise x au coords de depart.
			y++;
		}

		if ((y > len)) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas)
			return (4); 

		

		if (piece->piece[i] != '.') //ne s'occupe que des pieces deja presente 
		{

			if (square[y][x] != '.')
				return (3); //supperposition
		}
		i++;
		x++;
	}
	return (0);
}
