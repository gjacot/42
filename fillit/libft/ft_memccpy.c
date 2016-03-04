/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:23:34 by jgiraude          #+#    #+#             */
/*   Updated: 2015/12/08 02:52:15 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == (unsigned char)c)
			return ((void *)(ptr1 + 1));
		ptr1++;
		ptr2++;
	}
	return (NULL);
}
