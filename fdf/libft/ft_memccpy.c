/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:56:06 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/13 14:58:48 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			j;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	c2;

	j = 0;
	c2 = (unsigned char)c;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (n > j)
	{
		s2[j] = s1[j];
		if (s1[j] == c2)
			return (&s2[j + 1]);
		j++;
	}
	return (NULL);
}
