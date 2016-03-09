/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:28:34 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/09 19:34:37 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

t_piece	*mazpiece(t_piece *piece)
{
	t_piece *temp;

	temp = piece;
	while (piece->next != NULL)
	{
		piece = piece->next;
		piece->x = 0;
		piece->y = 0;
	}
	piece->x = 0;
	piece->y = 0;
	return (temp);
}

void	clean(char **square, t_piece *piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (square[j] != NULL)
	{
		if (square[j][i] >= piece->lettre)
			square[j][i] = '.';
		if (square[j][i] == '\0')
		{
			j++;
			i = -1;
		}
		i++;
	}
	mazpiece(piece);
}

char	**newsquare(int taille)
{
	char	**nvsquare;
	int		i;
	int		j;

	j = 0;
	nvsquare = ft_memalloc(sizeof(char *) * (taille + 1));
	while (j < taille)
	{
		i = 0;
		nvsquare[j] = ft_memalloc(sizeof(char) * (taille + 1));
		while (i < taille)
		{
			nvsquare[j][i] = '.';
			i++;
		}
		j++;
	}
	return (nvsquare);
}

char	**clearsquare(char **square, t_piece *piece, int taille)
{
	int tailleactuel;
	int j;

	j = 0;
	tailleactuel = ft_strlen(square[0]);
	if (tailleactuel < taille)
	{
		while (j < (tailleactuel + 1))
		{
			free(square[j]);
			j++;
		}
		free(square);
		square = newsquare(taille);
	}
	else
		clean(square, piece);
	return (square);
}
