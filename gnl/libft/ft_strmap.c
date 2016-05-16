/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:31:04 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/13 15:02:27 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*dest;

	if (s != NULL && f != NULL)
	{
		l = ft_strlen(s);
		dest = NULL;
		dest = (char *)ft_memalloc(l + 1);
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (i != l)
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i + 1] = '\0';
		return (dest);
	}
	return (NULL);
}
