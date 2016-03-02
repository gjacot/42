/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquargui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/02 18:20:33 by gjacot           ###   ########.fr       */
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
		if (i % 4 == 0)
		{
			x = piece->x;
			y++;
		}
		if (piece->piece[i] != '.')
		{
			if (square[y][x] != '.')
				return (1); // superposition
			if (x > len)
				return (2);
			if (y > len)
				return (3);
		}
		i++;
		x++;
	}
	return (0);
}
