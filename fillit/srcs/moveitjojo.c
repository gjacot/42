/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveitjojo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:19:47 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/09 19:21:47 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

char	**placeit(char **square, t_piece *piece)
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
		if (i % 4 == 0 && i > 0)
		{
			x = piece->x;
			y++;
		}
		if (piece->piece[i] != '.')
		{
			square[y][x] = piece->piece[i];
			dies++;
		}
		x++;
		i++;
	}
	return (square);
}

t_piece	*ft_pieceprev(char **square, t_piece *piece, int len)
{
	piece = piece->prev;
	clean(square, piece);
	piece->x++;
	if (piece->x > len - 1)
	{
		piece->x = 0;
		piece->y++;
	}
	return (piece);
}

t_piece	*moveit42(t_piece *piece, char **square, int verif, int *ok)
{
	if (verif == 0)
	{
		square = placeit(square, piece);
		if (piece->next != NULL)
			piece = piece->next;
		else
			*ok = 1;
	}
	else if (verif == 1)
	{
		if (piece->x > (int)(ft_strlen(square[0]) - 1))
		{
			piece->x = 0;
			piece->y++;
		}
		else
			piece->x++;
	}
	else if (verif == 2)
	{
		piece->y++;
		piece->x = 0;
	}
	return (piece);
}

char	**moveit(t_piece *piece, char **square)
{
	int verif;
	int len;
	int ok;

	ok = 0;
	while (ok == 0)
	{
		len = ft_strlen(square[0]);
		verif = verifsquare(square, piece);
		if (verif == 3)
		{
			if (piece->prev == NULL)
			{
				square = clearsquare(square, piece, len + 1);
				piece->x = 0;
				piece->y = 0;
			}
			else if (piece->prev != NULL)
				piece = ft_pieceprev(square, piece, len);
		}
		else
			piece = moveit42(piece, square, verif, &ok);
	}
	return (square);
}
