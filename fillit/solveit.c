/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:07:48 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 17:12:31 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

int		firstsquare(int i)
{
	if (i == 1)
		return (2);
	if (i == 2)
		return (3);
	if (i > 2 && i < 5)
		return (4);
	if (i > 4 && i < 7)
		return (5);
	if (i > 6 && i < 10)
		return (6);
	if (i > 9 && i < 13)
		return (7);
	if (i > 12 && i < 17)
		return (8);
	if (i > 16 && i < 21)
		return (9);
	if (i > 20 && i < 26)
		return (10);
	else
		return (11);
}

void	affiche(char **tab_piece)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab_piece[i] != NULL)
	{
		ft_putstr("tab_piece[");
		ft_putnbr(i);
		ft_putstr("]\n");
		while (j < 4)
		{
			ft_putnbr(tab_piece[i][j]);
			ft_putstr(" - ");
			j++;
		}
		ft_putstr("\n");
		i++;
		j = 0;
	}
}

int		solveit(char *buf)
{
	int		square;
	int		i;
	char	**tab_piece;

	i = 0;
	while (buf[i] != '\0')
		i++;
	i++;
	i = i / 21;
	square = firstsquare(i);
	tab_piece = initvar(buf);
	affiche(tab_piece);
	return (0);
}
