/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:38:46 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/20 19:20:32 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

static int		verif_collone(char *tab, int num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[num] == '#')
			return (1);
		num += 4;
		i++;
	}
	return (0);
}

static int		verif_ligne(char *tab, int num)
{
	int i;

	i = 0;
	num *= 4;
	while (i < 4)
	{
		if (tab[num] == '#')
			return (1);
		num += 1;
		i++;
	}
	return (0);
}

static void		update_ligne(char *tab)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (tab[i] == '#')
		{
			tab[i - 4] = tab[i];
			tab[i] = '.';
		}
		i++;
	}
}

static void		update_collone(char *tab)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (tab[i] == '#')
		{
			tab[i - 1] = tab[i];
			tab[i] = '.';
		}
		i++;
	}
}

void			posi(char *tab)
{
	int i;

	i = 2;
	while (i >= 0)
	{
		if (verif_collone(tab, 0) == 0)
			update_collone(tab);
		if (verif_ligne(tab, 0) == 0)
			update_ligne(tab);
		i--;
	}
}
