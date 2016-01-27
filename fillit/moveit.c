/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:18:55 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/27 14:57:10 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

int	moveit(t_piece piece, int taille, char *tab, char **square)
{
	int xy[2];
	int verif;

	while (piece->next)
	{
		xy[0] = piece->x;
		xy[1] = piece->y;
		verif = verifsquare(square, taille, tab, xy)
		if (verif == 0)
			piece = piece->next
		else if (verif == 1)
		{
			if (piece->prev)
			{
				piece = piece->prev;
				piece->x++;
			}
			else
			{
				while (piece->prev)
					piece = piece->prev;
			}
			clearsquare(piece);
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
