/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:55:35 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/03 14:40:10 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (ptr[i] != (unsigned char)c)
			i++;
		else
			return ((void *)&ptr[i]);
	}
	return (NULL);
}
