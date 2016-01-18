/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:07:48 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/18 13:46:01 by gjacot           ###   ########.fr       */
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
	ft_putnbr(square);
	return (0);
}
