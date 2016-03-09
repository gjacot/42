/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquargui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/09 18:01:44 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

int	verifsquare(char **square, t_piece *piece)
{
	INIT(int, i, 0);
	INIT(int, x, piece->x);
	INIT(int, y, piece->y);
	INIT(int, len, ft_strlen(square[0]));
	INIT(int, dies, 0);

	//clean(square, piece);
	affiche(square);
	while (dies < 4)
	{
		//break;
		if (i % 4 == 0 && i != 0 && y < len)
		{
				x = piece->x;
				y++;
		}
		if (y >= len) 
		{			
			return (3);
		}
		
		if (piece->piece[i] != '.')
		{
			if (x > len)
				return (2);
			printf("\033[33msquare[%d][%d] vaut '%c'\033[37m\n",y, x, square[y][x]);
			if (square[y][x] != '.')
			{
				printf("\033[32msquare[%d][%d] vaut '%c'\n",y, x, square[y][x]);
				printf("square[%d] = %s\n", y, square[y]);
				printf("lettre = '%c'\n\033[37m", piece->lettre);
				return (1);
			}
			
			dies++;
		}
		i++;
		x++;
	}
	return (0);
}
