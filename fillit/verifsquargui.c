/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquargui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/03 15:17:16 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

int	verifsquare(char **square, t_piece *piece)
{
	INIT(int, i, 0);
	INIT(int, x, piece->x);
	INIT(int, y, piece->y);
	INIT(int, len, ft_strlen(square[0]));

	len--;
	while (i < 15)
	{
		printf("i = %d\n", i);
		if (i % 4 == 0 && i != 0)
		{
				x = piece->x;
				y++;
				printf("et voila\n");
		}
		printf("piece->piece[%c]\n", piece->piece[i]);
		if (piece->piece[i] == piece->lettre)
		{
			if (square[y][x] != '.')
			{
				if (y > len - 1)
					return (3);
				else
					return (1);
			}// superposition
			if (x > len)
				return (2);
		}
		i++;
		x++;
	}
	return (0);
}
