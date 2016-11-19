/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:02:07 by gjacot            #+#    #+#             */
/*   Updated: 2015/11/25 17:02:11 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;
	int l;

	if (s != NULL)
	{
		i = 0;
		l = ft_strlen(s);
		while (l != i)
		{
			s[i] = '\0';
			i++;
		}
	}
}