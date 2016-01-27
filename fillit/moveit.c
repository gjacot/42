/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:18:55 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/27 17:40:23 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

void	moveit2(t_piece *piece, int taille)
{
	if (piece->next && piece->prev)
	{
		piece = piece->prev;
		piece->x++;
	}
	else
	{
		while (piece->prev)
		{
			taille++;
			piece = piece->prev;
		}
	}
}

void	moveit(t_piece *piece, int taille, char *tab, char **square)
{
	int xy[2];
	int verif;

	while (piece->next)
	{
		xy[0] = piece->x;
		xy[1] = piece->y;
		verif = verifsquare(square, taille, tab, xy);
		if (verif == 0)
			piece = piece->next;
		else if (verif == 1)
		{
			moveit2(piece, taille);
			square = clearsquare(square, piece->lettre, taille);
			moveit(piece, taille, tab, square);
		}
		else if (verif == 2)
		{
			piece->x = 0;
			piece->y++;
		}
		else if (verif == 3)
			piece->x++;
	}
}
