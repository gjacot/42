/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:22:40 by jgiraude          #+#    #+#             */
/*   Updated: 2016/02/17 17:08:27 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

int		verifsquare(char **square, t_piece *piece)
{
	INIT(int, i, 0);
	INIT(int, x, piece->x);
	INIT(int, y, piece->y);
	INIT(int, compteur, 0);
	INIT(int, len, ft_strlen(square[0]));
	y--;

	while (i < 15) //pour tout tab
	{
		if (i % 4 == 0 && compteur < 4)//pour changer de dimension dans square car square = char** et piece->piece = char *
		{
			x = piece->x; //reinitialise x au coords de depart.
			y++;
		}
		if (x >= len && piece->piece[i] != '.')
		{
			return (4);
		}
		if (y >= len) //y est sortie du tableau (sous entend qu'on a tester tout la piece et qu'elle ne rentre pas)
		{				//oublie du = car len commance a 1 et y a 0
			return (2); //la piece ne rentre pas, on passe a la piece precedante
		}
		if (piece->piece[i] != '.') //ne s'occupe que des pieces deja presente
		{
			if (square[y][x] != '.') //c'est cette PUTAIN de ligne qui fait chier car il test y = 3 et x = 0
			{
				return (3); //supperposition
			}
		}
		if (piece->piece[i] != '.')
		{
			compteur++;
			if (compteur == 4)
			{
				return (0);
			}
		}
		i++;
		x++;
	}
	return (0);
}
