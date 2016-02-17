/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:40:00 by gjacot            #+#    #+#             */
/*   Updated: 2016/02/17 19:36:06 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

char	**placepit(char **square, t_piece *piece)
{
	int x;
	int y;
	int dies;
	int i;

	x = piece->x;
	y = piece->y;
	dies = 0;
	i = 0;
	while (dies != 4)
	{
		if (piece->piece[i] != '.')
		{
			square[y][x] = piece->lettre;
			dies++;
		}
		if (x > (int)ft_strlen(square[0]))
		{
			x = 0;
			y++;
		}
		else
			x++;
		i++;
	}
	return (square);
}

void	ft_pieceprev(char **square, t_piece *piece)
{
	int len;

	len = ft_strlen(square[0]);
	piece->x = 0;
	piece->y = 0;
	piece = piece->prev;
	if (piece->x > len)
	{
		piece->x = 0;
		piece->y++;
	}
	else
		piece->x++;
	clearsquare(square, piece->lettre, len);
}

char	**moveit(t_piece *piece, char **square)
{
	int verif;
	int len;

	while (piece->next)
	{
		verif = verifsquare(square, piece);
		if (verif == 0)
		{
			square = placeit(square, piece);
			piece = piece->next;
		}
		else if (verif != 0 && verif != 2)
		{
			len = ft_strlen(square[0]);
			if (piece->x > len)
			{
				piece->x = 0;
				piece->y++;
			}
			else
				piece->x++;
		}
		else if(verif == 2)
			ft_pieceprev(square, piece);
	}
	return (square);
}










