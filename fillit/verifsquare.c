/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:22:40 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/20 20:45:10 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <libfillit.h>
#include <libft.h>
*/
int		verifsquare(char **square, int taille, char *tab, int coord[1])
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = coord[0];
	y = coord[1];
	while (i < 15) //pour tout tab
	{
		if ((y > taille) && (x > taille))
			return (1); //pas possible
		if (i % 4 == 0) //pour changer de dimension dans square
		{
			y++;
			x = coord[0]; //reinitialise j au coords de depart.
		}
		if (tab[i] == '#')
		{
			if (x + (i % 4) > taille)
				return (2); //supperieur a taille
			if (square[y][x + (i % 4)] == '#')
				return (3); //supperposition
		}
	}
	return (0);
}
