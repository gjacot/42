/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:07:48 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 14:38:19 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

int	firstsquare(int i)
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

int	compte_tab(char *buf)
{
	int i;
	int piece;

	piece = 1;
	i = 18;
	while (buf[i] != '\0')
	{
		if (buf[i - 1] != '\n' && buf[i - 2] != '\n')
			piece++;
		i++;
	}
	return (piece);
}

char	**remplir_tab(char *buf)
{
	int		nb_piece;
	char	**tab_piece;
	char	lettre;
	int		i;

	i = 0;
	lettre = 'A';
	nb_piece = compte_tab(buf);
	tab_piece = (char **)malloc(sizeof(char *) * nb_piece);
	while (i < 5)
		tab_piece[i++] = (char *)malloc(sizeof(char) * 5);
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n')
		{
			if (i % 5 == 0)
				tab_piece[lettre - 'A'][0] = lettre;
			else
				tab_piece[lettre - 'A'][i % 5] = buf[i];
		}
		if (buf[i - 1] != '\n' && buf[i - 2] != '\n')
			lettre++;
		i++;
	}
	return (tab_piece);
}

int	solveit(char *buf)
{
	int square;
	int i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	i++;
	i = i / 21;
	square = firstsquare(i);
	remplir_tab(buf);
	return (0);
}
