/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:38:46 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/21 15:33:42 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

int			verif_collone(char *tab, int num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[num] != '.')
			return (1);
		num += 4;
		i++;
	}
	return (0);
}

int			verif_ligne(char *tab, int num)
{
	int i;

	i = 0;
	num *= 4;
	while (i < 4)
	{
		if (tab[num] != '.')
			return (1);
		num += 1;
		i++;
	}
	return (0);
}

void		update_ligne(char *tab, char lettre)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (tab[i] != '.')
		{
			tab[i - 4] = lettre;
			tab[i] = '.';
		}
		i++;
	}
}

void		update_collone(char *tab, char lettre)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (tab[i] != '.')
		{
			tab[i - 1] = lettre;
			tab[i] = '.';
		}
		i++;
	}
}

void		posi(char *tab, int lettre)
{
	int		i;
	char	lettre1;

	i = 0;
	lettre1 = lettre + 'A';
	while (i < 15)
	{
		if (tab[i] == '#')
			tab[i] = lettre1;
		i++;
	}
	i = 2;
	while (i >= 0)
	{
		if (verif_collone(tab, 0) == 0)
			update_collone(tab, lettre1);
		if (verif_ligne(tab, 0) == 0)
			update_ligne(tab, lettre1);
		i--;
	}
}
