/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquargui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/03 18:01:45 by gjacot           ###   ########.fr       */
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
	INIT(int, dies, 0);

	len--;
	while (dies != 4)
	{
		break;
		if (i % 4 == 0 && i != 0 && y < len - 1)
		{
				x = piece->x;
				y++;
		}
		if (piece->piece[i] == piece->lettre)
		{
			if (square[y][x] != '.')
			{
				if (y > len - 1)
					return (3);
				else
				{
					printf("%d,%d", y,x);
					return (1);
				}
			}
			if (x > len)
				return (2);
			dies++;
		}
		i++;
		x++;
	}
	return (0);
}
