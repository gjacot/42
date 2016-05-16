/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:13:25 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/11 12:29:34 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int l;
	unsigned int j;

	if (s != NULL && f != NULL)
	{
		l = ft_strlen(s);
		j = 0;
		while (j != l)
		{
			f(j, &s[j]);
			j++;
		}
	}
}
