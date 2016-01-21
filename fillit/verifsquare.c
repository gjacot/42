/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:22:40 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/21 14:43:31 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <libfillit.h>
#include <libft.h>
*/
int		verifsquare(char **square, int taille, char *tab, int coord[1])
{
	int i;
	int x;
	int y;

	i = 0;
	x = coord[0];
	y = coord[1];
	if ((y >= taille) && (x >= taille))
			return (1); //pas possible
	while (i < 15) //pour tout tab
	{
		if (i % 4 == 0) //pour changer de dimension dans square
		{
			y++;
			x = coord[0]; //reinitialise x au coords de depart.
		}
		if (tab[i] == '#')
		{
			if ((x + (i % 4) > taille) || (y + (i % 4) > taille)) //a verif, pas sur avec y
				return (2); //supperieur a taille
			if (square[y][x + (i % 4)] == '#')
				return (3); //supperposition
		}
	}
	return (0);
}
