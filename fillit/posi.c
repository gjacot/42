/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:38:46 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/20 17:24:31 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

int		verif_collone(char *tab, int num)
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

int		verif_ligne(char *tab, int num)
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

void	update_ligne(char *tab, int var)
{
	int i;

	i = 0;
	var *= 4;
	while (i < 4)
	{
		if (var != 0)
		{
			tab[var - 4] = tab[var];
			tab[var] = '.';
			var++;
			i++;
		}
	}
}

void	update_collone(char *tab, int var)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (var != 0)
		{
			tab[var - 1] = tab[var];
			tab[var] = '.';
			var += 4;
			i++;
		}
	}
}

void	posi(char *tab)
{
	int var;

	var = 3;
	while (var > 0)
	{
		if (verif_ligne(tab, var) == 0)
			update_ligne(tab, var);
		if (verif_collone(tab, var) == 0)
			update_collone(tab, var);
		var--;
	}
}
