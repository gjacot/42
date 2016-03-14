/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:59:01 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/04 18:39:31 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

int		compte_tab(char *buf)
{
	int i;
	int piece;

	piece = 1;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
			piece++;
		i++;
	}
	return (piece);
}

void	**remplir_tab(char *buf, char **tab_piece)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i] != '\0')
	{
		if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
		{
			posi(tab_piece[j], j);
			j++;
			k = 0;
		}
		if (buf[i] != '\n')
		{
			tab_piece[j][k] = buf[i];
			k++;
		}
		i++;
	}
	posi(tab_piece[j], j);
	return (0);
}

char	**inittab(char *buf)
{
	int		i;
	int		nb_piece;
	char	**tab_piece;

	i = 0;
	nb_piece = compte_tab(buf);
	if (!(tab_piece = ft_memalloc(sizeof(char *) * nb_piece + 1)))
		error2("Probleme malloc\n", 1);
	tab_piece[nb_piece] = NULL;
	while (i < nb_piece)
	{
		if (!(tab_piece[i] = ft_memalloc(sizeof(char) * 17)))
			error2("Probleme malloc\n", 1);
		i++;
	}
	return (tab_piece);
}

char	**initsquare(int square)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = ft_memalloc(sizeof(char *) * square + 1)))
		error2("Probleme malloc (square)\n", 1);
	tab[square] = NULL;
	while (i < square)
	{
		if (!(tab[i] = ft_memalloc(sizeof(char) * square + 1)))
			error2("Probleme malloc (square)\n", 1);
		while (j < square)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (tab);
}
