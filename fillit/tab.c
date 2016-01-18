/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:59:01 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/18 17:03:17 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
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

char	**initvar(char *buf)
{
	int		j;
	int		k;
	int		l;
	char	**tab_piece;

	j = 0;
	k = 0;
	l = 0;
	tab_piece = remplir_tab(buf, j, k, l);
	return (tab_piece);
}

char	**remplir_tab(char *buf, int j, int k, int l)
{
	char	**tab_piece;
	int		i;

	i = 0;
	tab_piece = inittab(buf);
	while (buf[i] != '\0')
	{
		if (buf[i - 1] == '\n' && buf[i - 2] == '\n')
		{
			k = 0;
			l = 0;
			j++;
		}
		if (buf[i] == '#')
		{
			tab_piece[j][k] = l;
			k++;
		}
		if (buf[i] != '\n')
			l++;
		i++;
	}
	return (tab_piece);
}

char	**inittab(char *buf)
{
	int		i;
	int		nb_piece;
	char	**tab_piece;

	i = 0;
	nb_piece = compte_tab(buf);
	if (!(tab_piece = ft_memalloc(sizeof(char *) * nb_piece + 1)))
		error2("Probleme malloc\n");
	tab_piece[nb_piece] = NULL;
	while (i < nb_piece)
	{
		if (!(tab_piece[i] = ft_memalloc(sizeof(char) * 4)))
			error2("Probleme malloc\n");
		i++;
	}
	return (tab_piece);
}
