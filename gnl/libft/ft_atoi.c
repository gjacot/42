/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:14:20 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/17 15:56:44 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int i, int *neg, const char *str)
{
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		*neg = -1;
		i++;
	}
	if (str[i] == '+' && *neg != -1)
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int i;
	int nope;
	int nb;
	int neg;
	int *neg2;

	i = 0;
	nope = 0;
	nb = 0;
	neg = 1;
	neg2 = &neg;
	i = ft_check(i, neg2, str);
	while (nope == 0 && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			nb = nb + str[i] - '0';
			if (str[i + 1] != '\0' && ft_isdigit(str[i + 1]) == 1)
				nb = nb * 10;
			i++;
		}
		else
			nope = 1;
	}
	return (nb * neg);
}
