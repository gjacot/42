/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveitjojo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:19:47 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/07 15:04:11 by jgiraude         ###   ########.fr       */
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
	affiche(square);
	printf("\n");
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
			affiche(square);
			printf("\n");
			dies++;
		}
		x++;
		i++;
	}
	return (square);
}

void	ft_pieceprev(char **square, t_piece *piece, int len)
{
		piece->x = 0;
		piece->y = 0;
		piece = piece->prev;
		if (piece->x > len - 1)
		{
			piece->x = 0;
			piece->y++;
		}
		else
			piece->x++;
		clearsquare(square, piece, len);
}

char	**moveit(t_piece *piece, char **square)
{
	int verif;
	int len;
	int ok;

	ok = 0;
	len = ft_strlen(square[0]);
	while (ok == 0)
	{
		verif = verifsquare(square, piece);
		printf("------\nverif = %d\npiece[%c] %d,%d\n", verif, piece->lettre, piece->y, piece->x);
		if (verif == 0)
		{
			square = placeit(square, piece);
			if (piece->next != NULL)
				piece = piece->next;
			else
				ok = 1;
		}
		else if (verif == 1)
		{
			if (piece->x > len - 1)
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
		else if (verif == 3)
		{
			if (piece->prev == NULL)
			{
				len++;
				clearsquare(square, piece, len);
				piece->x = 0;
				piece->y = 0;
			}
			else if (piece->prev != NULL)
			{
				ft_pieceprev(square, piece, len);
				piece = piece->prev;
			}
		}
		if (piece->y > len -1)
			piece->y = 0;
	}
	ft_putstr("kangourou\n\0");
	return (square);
}
