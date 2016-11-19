/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:48:36 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/22 16:42:21 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*s3;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	s3 = (unsigned char *)malloc(len);
	i = 0;
	if (s3 == NULL)
		return (NULL);
	while (i < len)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		s2[i] = s3[i];
		i++;
	}
	free(s3);
	return (dst);
}
