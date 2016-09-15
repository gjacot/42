/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:05:53 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/17 15:58:38 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_allocandxept(int n)
{
	int		j;
	int		nb;

	j = 0;
	nb = n;
	if (n < 0)
		j++;
	while (nb != 0)
	{
		nb = nb / 10;
		j++;
	}
	return (j + 1);
}

static char		*ft_itoaend(int n, char *dest, char *rdest, int i)
{
	int		j;
	int		nb;

	j = 0;
	nb = n;
	while (n > 0)
	{
		nb = n % 10;
		n = n / 10;
		dest[j] = nb + '0';
		j++;
	}
	while (j != 0)
	{
		j--;
		rdest[i] = dest[j];
		i++;
	}
	rdest[i] = '\0';
	return (rdest);
}

char			*ft_itoa(int n)
{
	char	*dest;
	char	*rdest;
	int		i;

	i = 0;
	dest = NULL;
	rdest = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dest = (char *)ft_memalloc(ft_allocandxept(n));
	rdest = (char *)ft_memalloc(ft_allocandxept(n));
	if (dest == NULL || rdest == NULL)
		return (NULL);
	if (n < 0)
	{
		rdest[i] = '-';
		n = -n;
		i++;
	}
	return (ft_itoaend(n, dest, rdest, i));
}
