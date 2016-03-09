/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquargui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/09 20:00:06 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

int	verifsquare(char **square, t_piece *piece, int dies)
{
	INIT(int, i, 0);
	INIT(int, x, piece->x);
	INIT(int, y, piece->y);
	INIT(int, len, ft_strlen(square[0]));

	while (dies < 4)
	{
		if (i % 4 == 0 && i != 0 && y < len)
		{
				x = piece->x;
				y++;
		}
		if (y >= len) 
			return (3);
		if (piece->piece[i] != '.')
		{
			if (x > len)
				return (2);
			if (square[y][x] != '.')
				return (1);
			dies++;
		}
		i++;
		x++;
	}
	return (0);
}
