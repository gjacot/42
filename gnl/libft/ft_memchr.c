/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:02:33 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/17 14:06:28 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cpy;
	unsigned char	*str;

	i = 0;
	cpy = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == cpy)
			return (str + i);
		i++;
	}
	return (NULL);
}
