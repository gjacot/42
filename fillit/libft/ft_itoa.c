/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:14:09 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/09 16:51:11 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc_itoa(int *n, int *neg)
{
	int temp;
	int len;

	len = 0;
	temp = *n;
	if (*n < 0)
	{
		*neg = 1;
		*n *= -1;
	}
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

static void		ft_itoa2(int n, char *str, int len, int neg)
{
	str[len + neg] = '\0';
	len--;
	while (len >= 0)
	{
		str[len + neg] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (neg == 1)
		str[0] = '-';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	len = calc_itoa(&n, &neg);
	if (n != 0)
	{
		str = (char*)malloc((len + neg + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_bzero(str, (len + neg + 1));
		if (n == -2147483648)
			ft_strcpy(str, "-2147483648");
		else
			ft_itoa2(n, str, len, neg);
	}
	else
	{
		str = (char *)malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}
