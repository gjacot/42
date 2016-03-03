/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:40:00 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/03 15:24:43 by gjacot           ###   ########.fr       */
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

int		ft_verifpieceactu(char **square, char lettre, int len)
{
	int i;
	int j;
	int fail;
	int fail2;

	i = 0;
	j = 0;
	fail = 0;
	fail2 = 0;
	while (i < len)
	{
		while (j < len)
		{
			printf("----------\ni=%d\nj=%d\nlen = %d\nlettre = %c\n", i, j, len, lettre);
			if (square[i][j] == lettre)
			{
				if (j != len - 1)
				{
					if (square[i][j + 1] != lettre && square[i][j + 1] != '.')
						fail = 1;
				}
				else
					fail = 1;
				if (i != len - 1)
				{
					if (square[i + 1][j] != lettre && square[i + 1][j] != '.')
						fail2 = 2;
				}
				else
					fail2 = 2;
			}
			j++;
		}
		i++;
		j = 0;
	}
		printf("fail=%d fail2=%d\n",fail,fail2);
		return (fail + fail2);
}


void	ft_pieceprev(char **square, t_piece *piece, int len)
{
	int verif;

	printf("--------ft_pieceprev--------\n");
	printf("PIECE ACTU->%c\n",piece->lettre);
	verif = ft_verifpieceactu(square, piece->lettre, len);
	printf("verif = %d\n", verif);
	/*if (verif == 3)
	  {*/
		piece->x = 0;
		piece->y = 0;
		piece = piece->prev;
		piece->x++;
		printf ("piece->y = %d\n", piece->y);
		if (piece->x > len)
		{
			piece->x = 0;
			piece->y++;
		}
		clearsquare(square, piece->lettre, len);
		printf("PIECE ACTU->%c\n",piece->lettre);
		//}
	clearsquare(square, piece->lettre, len);
/*if (verif <= 1)
		piece->x++;
	else
	piece->y++;*/
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
		printf("verif = %d\n", verif);
		if (verif == 0)
		{
			square = placeit(square, piece, len);
			if (piece->next != NULL)
			{
				printf("---------------ok-------------\n");
				piece = piece->next;
			}
			else
				ok = 1;
		}
		else if (verif == 1)
		{
			printf("piece->y = %d\n", piece->y);
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
				clearsquare(square, piece->lettre, len);
			}
			else if (piece->prev != NULL)
			{
				printf("ok\n");
				ft_pieceprev(square, piece, len);
				piece = piece->prev;
			}
		}
		if (piece->y > len -1)
			piece->y = 0;
	}
	return (square);
}
