/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:18:55 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 15:52:39 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

int	moveit(t_piece piece, int square, char *tab, char **rsquare)
{
	int xy[2];
	int verif;

	while ()
	{
		xy[0] = piece->x;
		xy[1] = piece->y;
		verif = verifsquare(rsquare, square, tab, xy)
		if (verif == 0)
		{

		}
		else if (verif == 1)
		{

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



