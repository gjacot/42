/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:23:04 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/10 20:45:38 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>
#include <stdio.h>

int	countlline(int *buf)
{

}

int	lastcheck(char *buf)
{
	int i;
	int j;
	int die[4];
	int fj;
	int nbd;

	i = 0;
	j = 0;
	fi = i;
	nbd = 0;
	while (buf[i] != '\0')
	{
		while (nbd != 4)
		{
			while (buf[i] != '#')
				i++;
			die[j] = i;
			nbd++;
			i++;
			j++;
		}
		if (!(countline(die) == 8 || coutline(die) == 6));
			error();
		line = 0;
		i = fi + 21;
		fi = i;
		nbd = 0;
	}
	ft_putstr("ok\n");
	return (1);
}












