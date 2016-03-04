/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifpiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:07:09 by jgiraude          #+#    #+#             */
/*   Updated: 2016/02/10 17:15:33 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

t_piece	*verifpiece2(t_piece *piece, int lettre)
{
	int lettre2;

	lettre2 = piece->lettre;
	if (lettre2 - lettre > 0)
	{
		while (lettre2 - lettre > 0)
		{
			piece = piece->prev;
			lettre2--;
		}
	}
	else
	{
		while (lettre - lettre2 > 0)
		{
			piece = piece->next;
			lettre--;
		}
	}
	return (piece);
}

t_piece	*verifpiece(t_piece *piece, char **square)
{
	int		i;
	int		j;
	char	lettre;

	j = 0;
	lettre = 'A';
	while (square[j] != NULL)
	{
		i = 0;
		while (square[j][i] != '\0')
		{
			if (square[j][i] == lettre)
				lettre++;
			i++;
		}
		j++;
	}
	piece = verifpiece2(piece, lettre);
	return (piece);
}
