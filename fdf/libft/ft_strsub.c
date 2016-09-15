/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:19:48 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/22 11:59:20 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*dest;

	j = 0;
	dest = NULL;
	dest = (char *)ft_memalloc(len + 1);
	if (dest != NULL && s != NULL)
	{
		while (j != len)
		{
			dest[j] = s[start + j];
			j++;
		}
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}
