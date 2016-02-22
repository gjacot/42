/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:40:00 by gjacot            #+#    #+#             */
/*   Updated: 2016/02/22 14:09:06 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

char	**placeit(char **square, t_piece *piece, int len)
{
	int x;
	int y;
	int dies;
	int i;

	printf("--------placeit--------\n");
	x = piece->x;
	y = piece->y;
	dies = 0;
	i = 0;
	affiche(square);
	printf("len = %d\n", len);
	while (dies != 4)
	{
		printf("x = %d\ny = %d\ni = %d\npiece[i] = %c\n", x, y, i, piece->piece[i]);
		if (piece->piece[i] != '.')
		{
			printf("----------------------------\n");
			square[y][x] = piece->piece[i];
			affiche(square);
			dies++;
		}
		if (x >= len - 1)
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

void	ft_pieceprev(char **square, t_piece *piece, int len)
{
	printf("--------ft_pieceprev--------\n");
	piece->x = 0;
	piece->y = 0;
	piece = piece->prev;
	piece->x++;
	if (piece->x > len)
	{
		piece->x = 0;
		piece->y++;
	}
	clearsquare(square, piece->lettre, len);
}

char	**moveit(t_piece *piece, char **square)
{
	int verif;
	int len;
	int ok;

	printf("--------moveit--------\n");
	ok = 0;
	len = ft_strlen(square[0]);
	while (ok == 0)
	{
		verif = verifsquare(square, piece);
		if (verif == 0)
		{
			square = placeit(square, piece, len);
			if (piece->next != NULL)
				piece = piece->next;
			else
				ok = 1;
		}
		else if (verif != 0 && verif != 2)
		{
			if (piece->x > len)
			{
				piece->x = 0;
				piece->y++;
			}
			else
				piece->x++;
		}
		else if (verif == 2 && piece->prev == NULL)
		{
			len++;
			clearsquare(square, piece->lettre, len);
		}
		else if (verif == 2 && piece->prev != NULL)
			ft_pieceprev(square, piece, len);
	}
	return (square);
}
