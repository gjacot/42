/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:02:53 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/09 16:50:42 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isdigite(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_atoi(char *s)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
				s[i] == '\v' || s[i] == '\f' || s[i] == '\r') && (s[i] != '\0'))
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (!ft_isdigite(s[i]))
			return (res * neg);
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * neg);
}
